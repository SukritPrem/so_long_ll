/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:00:41 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/16 16:26:49 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list_line(t_list_line *list_line)
{
	list_line->current = list_line->head;
	while (list_line->current)
	{
		list_line->clone = list_line->current->next;
		free(list_line->current->line);
		free(list_line->current);
		list_line->current = list_line->clone;
	}
}

void	free_map(char ***map_main)
{
	char	**map;
	int		i;

	i = 0;
	map = *map_main;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_list_background(t_list_map *list_background, t_mlx *board_mlx)
{
	list_background->current = list_background->head;
	while (list_background->current)
	{
		list_background->clone = list_background->current->next;
		mlx_destroy_image(board_mlx, list_background->current->picture->img);
		list_background->current->picture->img = NULL;
		free(list_background->current->picture);
		list_background->current->picture = NULL;
		free(list_background->current);
		list_background->current = NULL;
		list_background->current = list_background->clone;
	}
	list_background->head = NULL;
	list_background->current = NULL;
}

void	free_player(t_player *player, t_mlx *board_mlx)
{
	mlx_destroy_image(board_mlx, player->head->picture->img);
	free(player->head->picture);
	free(player->head);
}

void	free_item(t_list_item *list_item, t_mlx *board_mlx)
{
	int	i;

	i = 0;
	while (list_item->item[i])
	{
		if (i < list_item->count_all_item)
		{
			if (list_item->item[i]->picture)
				free(list_item->item[i]->picture);
			free(list_item->item[i]);
		}
		i++;
	}
	free(list_item->item);
}
