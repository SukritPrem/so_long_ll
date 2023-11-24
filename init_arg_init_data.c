/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg_init_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:18:52 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:20:24 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, t_arg *arg)
{
	data->list_player = &arg->player;
	data->map = arg->map;
	data->list_background = &arg->list_background;
	data->list_wall = &arg->list_wall;
	data->list_item = &arg->item;
	data->list_exit = &arg->exit;
	data->board_mlx = &arg->board_mlx;
}

void	init_arg(t_arg *arg, t_list_line *list_line)
{
	arg->list_line = list_line;
	reset_value(arg);
	arg->map = init_map(list_line, arg);
	check_all_character(arg);
	reset_value(arg);
	arg->map_copy = init_map(list_line, arg);
	arg->count_item = 0;
	arg->count_exit = 0;
	flood_fill_check_map(arg, arg->i_y, arg->i_x);
	check_player_find_c_e(arg);
	free_map(&arg->map_copy);
	arg->map_copy = NULL;
	reset_value(arg);
	arg->map_copy = init_map(list_line, arg);
	arg->count_item = 0;
	flood_fill_check_map_pec(arg, arg->i_y, arg->i_x);
	check_player_find_c_e(arg);
	free_list_line(arg->list_line);
}

void	reset_value(t_arg *arg)
{
	arg->count_all_item = 0;
	arg->count_player = 0;
	arg->count_all_exit = 0;
	arg->have_dif_char = 0;
}
