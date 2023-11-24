/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:22:58 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:23:03 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->list_wall->current = data->list_wall->head;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(\
						data->board_mlx->mlx, \
						data->board_mlx->mlx_win, \
						data->list_wall->current->picture->img, \
						data->list_wall->current->pos_x, \
						data->list_wall->current->pos_y);
				data->list_wall->current = data->list_wall->current->next;
			}
			j++;
		}
		i++;
	}
}

void	render_item(t_data *data)
{
	int	i;

	i = 0;
	data->list_item->index = 0;
	if (data->list_item->item == NULL)
		return ;
	while (i < data->list_item->count_all_item)
	{
		if (data->list_item->item[i]->picture != NULL)
			mlx_put_image_to_window(data->board_mlx->mlx, \
					data->board_mlx->mlx_win, \
					data->list_item->item[i]->picture->img, \
					data->list_item->item[i]->pos_x, \
					data->list_item->item[i]->pos_y);
		i++;
	}
}

void	render_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_destroy_image(data->board_mlx->mlx, \
			data->list_player->head->picture->img);
	create_img_player(data);
	mlx_put_image_to_window(data->board_mlx->mlx, data->board_mlx->mlx_win, \
			data->list_player->head->picture->img, \
			data->list_player->head->pos_x, data->list_player->head->pos_y);
}

void	render_exit(t_data *data)
{
	if (data->list_player->item == data->list_item->count_all_item)
	{
		mlx_destroy_image(data->board_mlx->mlx, \
				data->list_exit->head->picture->img);
		data->list_exit->head->picture->img = mlx_xpm_file_to_image(\
				data->board_mlx->mlx, "./xpm_file/exit/tile001.xpm", \
				&data->list_exit->head->picture->width, \
				&data->list_exit->head->picture->height);
		mlx_put_image_to_window(data->board_mlx->mlx, data->board_mlx->mlx_win, \
				data->list_exit->head->picture->img, \
				data->list_exit->head->pos_x, data->list_exit->head->pos_y);
	}
	else
		mlx_put_image_to_window(data->board_mlx->mlx, data->board_mlx->mlx_win, \
				data->list_exit->head->picture->img, \
				data->list_exit->head->pos_x, data->list_exit->head->pos_y);
}

int	render(t_data *data)
{
	render_background(data);
	render_wall(data);
	render_item(data);
	render_player(data);
	render_exit(data);
	return (0);
}
