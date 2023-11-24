/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:20:23 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:35:01 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_head_list_player(t_arg *arg, int i, int j)
{
	arg->player.head = create_list_background(\
			arg->list_background.current->pos_x, \
			arg->list_background.current->pos_y, 'P', \
			arg->board_mlx.mlx);
	if (arg->player.head == NULL)
	{
		free_list_background(&arg->list_background, arg->board_mlx.mlx);
		free_list_background(&arg->list_wall, arg->board_mlx.mlx);
		free_map(&arg->map);
		exit(1);
	}
	arg->player.right = 1;
	arg->player.left = 0;
	arg->player.up = 0;
	arg->player.down = 0;
	arg->player.pos_i_x = i;
	arg->player.pos_i_y = j;
	arg->player.store_all_move = 1;
	arg->player.item = 0;
}

void	create_list_head_exit(t_arg *arg)
{
	arg->exit.exit = 0;
	arg->exit.head = create_list_background(arg->list_background.current->pos_x,
			arg->list_background.current->pos_y, 'E', arg->board_mlx.mlx);
	if (arg->exit.head == NULL)
	{
		free_list_background(&arg->list_background, arg->board_mlx.mlx);
		free_list_background(&arg->list_wall, arg->board_mlx.mlx);
		free_player(&arg->player, arg->board_mlx.mlx);
		free_map(&arg->map);
		exit(1);
	}
}

void	init_player(t_arg *arg)
{
	int	i;
	int	j;

	arg->item.count_all_item = 0;
	arg->list_background.current = arg->list_background.head;
	i = 0;
	j = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'P')
				create_head_list_player(arg, i, j);
			if (arg->map[i][j] == 'C')
				arg->item.count_all_item++;
			if (arg->map[i][j] == 'E')
				create_list_head_exit(arg);
			arg->list_background.current = arg->list_background.current->next;
			j++;
		}
		i++;
	}
}
