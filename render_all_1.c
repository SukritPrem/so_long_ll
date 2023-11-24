/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:22:00 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:27:12 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_mlx_background(t_data *data)
{
	mlx_put_image_to_window(\
		data->board_mlx->mlx, \
		data->board_mlx->mlx_win, \
		data->list_background->current->picture->img, \
		data->list_background->current->pos_x, \
		data->list_background->current->pos_y);
	data->list_background->current = \
			data->list_background->current->next;
}

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->list_background->current = data->list_background->head;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->list_player->head->pos_x = \
					data->list_background->current->pos_x;
				data->list_player->head->pos_y = \
					data->list_background->current->pos_y;
			}
			render_mlx_background(data);
			j++;
		}
		i++;
	}
}
