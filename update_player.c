/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:15:54 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:33:50 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_update_player(t_update_player *data_update, t_data *data,
		int condition_left_right, int condition_up_down)
{
	data_update->x = data->list_player->pos_i_x;
	data_update->y = data->list_player->pos_i_y;
	data_update->i = condition_up_down;
	data_update->j = condition_left_right;
}

void	set_data_player(t_data *data, t_update_player *data_update)
{
	data->map[data_update->x][data_update->y] = '0';
	data->map[data_update->i][data_update->j] = 'P';
	data->list_player->pos_i_y = data_update->j;
	data->list_player->pos_i_x = data_update->i;
	ft_putstr_fd("number all move :", 1);
	ft_putnbr_fd(data->list_player->store_all_move, 1);
	ft_putchar_fd('\n', 1);
	data->list_player->store_all_move++;
}

void	remove_all(t_data *data)
{
	free_item(data->list_item, data->board_mlx->mlx);
	free_list_background(data->list_background, data->board_mlx->mlx);
	free_list_background(data->list_wall, data->board_mlx->mlx);
	free_player(data->list_player, data->board_mlx->mlx);
	free_exit(data->list_exit, data->board_mlx->mlx);
	free_map(&data->map);
	mlx_clear_window(data->board_mlx->mlx, data->board_mlx->mlx_win);
	mlx_destroy_window(data->board_mlx->mlx, data->board_mlx->mlx_win);
	exit(0);
}

void	update_player(t_data *data, int condition_left_right,
		int condition_up_down)
{
	t_update_player	data_update;

	set_update_player(&data_update, data, condition_left_right, \
			condition_up_down);
	if (data->map[data_update.i][data_update.j] == '0')
		set_data_player(data, &data_update);
	else if (data->map[data_update.i][data_update.j] == 'C')
	{
		set_data_player(data, &data_update);
		update_item(data);
	}
	else if (data->map[data_update.i][data_update.j] == 'E' &&
				data->list_player->item == data->list_item->count_all_item)
		remove_all(data);
}
