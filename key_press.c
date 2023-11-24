/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:18:06 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 17:41:50 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_w(t_data *data)
{
	data->list_player->up = data->list_player->up + 1;
	set_keypress_to_up(data);
	if (data->list_player->up > 1)
		update_player(data, data->list_player->pos_i_y, \
				data->list_player->pos_i_x - 1);
}

void	press_s(t_data *data)
{
	data->list_player->down = data->list_player->down + 1;
	set_keypress_to_down(data);
	if (data->list_player->down > 1)
		update_player(data, data->list_player->pos_i_y, \
				data->list_player->pos_i_x + 1);
}

void	press_esc(t_data *data)
{
	free_list_background(data->list_background, data->board_mlx->mlx);
	free_list_background(data->list_wall, data->board_mlx->mlx);
	free_player(data->list_player, data->board_mlx->mlx);
	free_exit(data->list_exit, data->board_mlx->mlx);
	free_item(data->list_item, data->board_mlx->mlx);
	free_map(&data->map);
	mlx_destroy_window(data->board_mlx->mlx, data->board_mlx->mlx_win);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_A)
		press_a(data);
	else if (keycode == KEY_D)
		press_d(data);
	else if (keycode == KEY_W)
		press_w(data);
	else if (keycode == KEY_S)
		press_s(data);
	else if (keycode == KEY_ESC)
		press_esc(data);
	return (0);
}
