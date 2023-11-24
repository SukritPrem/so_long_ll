/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_item_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:24:36 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:25:55 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_item_left(t_data *data, int i)
{
	data->list_player->item++;
	mlx_destroy_image(data->board_mlx->mlx, \
			data->list_item->item[i]->picture->img);
	free(data->list_item->item[i]->picture);
	data->list_item->item[i]->picture = NULL;
}

void	update_item_right(t_data *data, int i)
{
	data->list_player->item++;
	mlx_destroy_image(data->board_mlx->mlx, \
			data->list_item->item[i]->picture->img);
	free(data->list_item->item[i]->picture);
	data->list_item->item[i]->picture = NULL;
}

void	update_item_up(t_data *data, int i)
{
	data->list_player->item++;
	mlx_destroy_image(data->board_mlx->mlx, \
			data->list_item->item[i]->picture->img);
	free(data->list_item->item[i]->picture);
	data->list_item->item[i]->picture = NULL;
}

void	update_item_down(t_data *data, int i)
{
	data->list_player->item++;
	mlx_destroy_image(data->board_mlx->mlx, \
			data->list_item->item[i]->picture->img);
	free(data->list_item->item[i]->picture);
	data->list_item->item[i]->picture = NULL;
}
