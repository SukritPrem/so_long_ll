/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:13:24 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/13 13:56:25 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*create_list_background(int pos_x, int pos_y, char type, void *mlx)
{
	t_list_map	list_background;

	list_background.head = malloc(sizeof(t_map));
	if (list_background.head == NULL)
		error_malloc(&list_background, MALLOC_ERROR_LIST_BACK);
	list_background.head->pos_x = pos_x;
	list_background.head->pos_y = pos_y;
	list_background.head->type = type;
	list_background.head->picture = malloc(sizeof(t_img));
	if (list_background.head->picture == NULL)
		error_malloc(&list_background, MALLOC_ERROR_PIC);
	list_background.head->picture->img = create_img_and_get_w_and_h(mlx,
			list_background.head->type, &list_background.head->picture->width,
			&list_background.head->picture->height);
	if (list_background.head->picture->img == NULL)
		error_malloc(&list_background, MALLOC_ERROR_IMG);
	list_background.head->next = NULL;
	return (list_background.head);
}

t_map	*error_malloc(t_list_map *list_background, int error_case)
{
	if (error_case == MALLOC_ERROR_LIST_BACK)
	{
		write(2, "Error malloc list back ground\n", 31);
		return (NULL);
	}
	else if (error_case == MALLOC_ERROR_PIC)
	{
		write(2, "Error malloc picture\n", 22);
		free(list_background->head);
		return (NULL);
	}
	else if (error_case == MALLOC_ERROR_IMG)
	{
		write(2, "Error create img\n", 18);
		free(list_background->head->picture);
		free(list_background->head);
		return (NULL);
	}
	return (NULL);
}

void	*create_img_and_get_w_and_h(void *mlx, char type, int *w, int *h)
{
	void	*answer;

	if (type == 'B')
		return (mlx_xpm_file_to_image(mlx,
				"./xpm_file/floor/pixil-frame-0-_3_.xpm", w, h));
	else if (type == 'W')
		return (mlx_xpm_file_to_image(mlx,
				"./xpm_file/wall/pixil-frame-0-_6_.xpm", w, h));
	else if (type == 'P')
		return (mlx_xpm_file_to_image(mlx, "./xpm_file/player/tile000.xpm", w,
				h));
	else if (type == 'C')
		return (mlx_xpm_file_to_image(mlx, "./xpm_file/item/tile000.xpm", w,
				h));
	else if (type == 'E')
		return (mlx_xpm_file_to_image(mlx, "./xpm_file/exit/tile000.xpm", w,
				h));
	else
		return (NULL);
}

void	create_img_player(t_data *data)
{
	if (data->list_player->left > 0 && data->list_player->head->type == 'P')
		data->list_player->head->picture->img = mlx_xpm_file_to_image(\
				data->board_mlx->mlx, "./xpm_file/player/tile001.xpm", \
				&data->list_player->head->picture->width, \
				&data->list_player->head->picture->height);
	else if (data->list_player->right > 0 && \
			data->list_player->head->type == 'P')
		data->list_player->head->picture->img = mlx_xpm_file_to_image(\
				data->board_mlx->mlx, "./xpm_file/player/tile000.xpm", \
				&data->list_player->head->picture->width, \
				&data->list_player->head->picture->height);
	else if (data->list_player->down > 0 && \
			data->list_player->head->type == 'P')
		data->list_player->head->picture->img = mlx_xpm_file_to_image(\
				data->board_mlx->mlx, "./xpm_file/player/tile002.xpm", \
				&data->list_player->head->picture->width, \
				&data->list_player->head->picture->height);
	else if (data->list_player->up > 0 && \
			data->list_player->head->type == 'P')
		data->list_player->head->picture->img = mlx_xpm_file_to_image(\
				data->board_mlx->mlx, "./xpm_file/player/tile003_1.xpm", \
				&data->list_player->head->picture->width, \
				&data->list_player->head->picture->height);
}
