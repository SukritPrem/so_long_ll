/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:51:25 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/21 15:29:48 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_check_map(t_arg *arg, int y, int x)
{
	if (x == -1 || x == arg->width_map || y == -1 || y == arg->height_map
		|| arg->map_copy[y][x] == 'D' || arg->map_copy[y][x] == '1')
	{
		if (x == arg->width_map || y == arg->height_map || x == -1 || y == -1)
			arg->have_dif_char = 1;
		return ;
	}
	if (arg->map_copy[y][x] == 'C')
		arg->count_item++;
	if (arg->map_copy[y][x] == 'E')
	{
		arg->count_exit++;
	}
	arg->map_copy[y][x] = 'D';
	flood_fill_check_map(arg, y - 1, x);
	flood_fill_check_map(arg, y + 1, x);
	flood_fill_check_map(arg, y, x - 1);
	flood_fill_check_map(arg, y, x + 1);
}

void	flood_fill_check_map_pec(t_arg *arg, int y, int x)
{
	if (x == 0 || x == arg->width_map || y == 0 || y == arg->height_map \
			|| arg->map_copy[y][x] == 'L' || \
			arg->map_copy[y][x] == '1' || arg->map_copy[y][x] == 'E')
	{
		return ;
	}
	if (arg->map_copy[y][x] == 'C')
		arg->count_item++;
	arg->map_copy[y][x] = 'L';
	flood_fill_check_map_pec(arg, y - 1, x);
	flood_fill_check_map_pec(arg, y + 1, x);
	flood_fill_check_map_pec(arg, y, x - 1);
	flood_fill_check_map_pec(arg, y, x + 1);
}

void	check_all_character(t_arg *arg)
{
	if (arg->count_all_exit != 1 || arg->count_all_item == 0
		|| arg->count_player != 1 || arg->have_dif_char > 0)
	{
		if (arg->count_all_exit != 1)
			write(2, "Error E in map\n", 28);
		else if (arg->count_all_item == 0)
			write(2, "Error does not have C in map\n", 28);
		else if (arg->have_dif_char > 0)
			write(2, "Error have some character does not_pec10 \n", 43);
		else if (arg->count_player != 1)
			write(2, "Error P in map\n", 30);
		free_list_line(arg->list_line);
		free_map(&arg->map);
		exit(1);
	}
}

void	check_player_find_c_e(t_arg *arg)
{
	if (arg->count_all_exit != arg->count_exit
		|| arg->count_all_item != arg->count_item || arg->have_dif_char > 0)
	{
		if (arg->count_all_exit != arg->count_exit)
			write(2, "Error can't go to E in map\n", 28);
		else if (arg->count_all_item != arg->count_item)
			write(2, "Error can't go to C in map\n", 28);
		else if (arg->have_dif_char > 0)
			write(2, "Error wall does not complete \n", 31);
		free_list_line(arg->list_line);
		free_map(&arg->map);
		free_map(&arg->map_copy);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_list_line	list_line;
	t_arg		arg;
	t_data		data;

	init_list_line(argv, &list_line);
	init_arg(&arg, &list_line);
	init_list_background_and_board_mlx(&arg);
	init_list_wall(&arg);
	init_player(&arg);
	init_item(&arg);
	init_data(&data, &arg);
	mlx_loop_hook(arg.board_mlx.mlx, &render, &data);
	mlx_hook(arg.board_mlx.mlx_win, KEY_EVENT, KEY_MASK, key_press, &data);
	mlx_hook(arg.board_mlx.mlx_win, KEY_EXIT, KEY_MASK, key_press_exit, &data);
	mlx_loop(arg.board_mlx.mlx);
	exit(0);
}
