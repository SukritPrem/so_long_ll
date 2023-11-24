/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:42:14 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:17:28 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_a(t_data *data)
{
	data->list_player->left = data->list_player->left + 1;
	set_keypress_to_left(data);
	if (data->list_player->left > 1)
		update_player(data, data->list_player->pos_i_y - 1, \
				data->list_player->pos_i_x);
}

void	press_d(t_data *data)
{
	data->list_player->right = data->list_player->right + 1;
	set_keypress_to_right(data);
	if (data->list_player->right > 1)
		update_player(data, data->list_player->pos_i_y + 1, \
				data->list_player->pos_i_x);
}

int	key_press_exit(t_data *data)
{
	free_list_background(data->list_background, data->board_mlx->mlx);
	free_list_background(data->list_wall, data->board_mlx->mlx);
	free_player(data->list_player, data->board_mlx->mlx);
	free_exit(data->list_exit, data->board_mlx->mlx);
	free_item(data->list_item, data->board_mlx->mlx);
	free_map(&data->map);
	exit(0);
	return (0);
}
