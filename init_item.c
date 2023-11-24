/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:21:50 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/16 16:29:59 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_item_1(t_arg *arg)
{
	arg->item.item[arg->item.index] = create_list_background(\
			arg->list_background.current->pos_x, \
			arg->list_background.current->pos_y, 'C', \
			arg->board_mlx.mlx);
	arg->item.index++;
}

void	init_item(t_arg *arg)
{
	int	i;
	int	j;

	arg->item.item = malloc(sizeof(t_map *) * (arg->item.count_all_item + 1));
	arg->list_background.current = arg->list_background.head;
	arg->item.index = 0;
	i = 0;
	j = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'C')
				init_item_1(arg);
			j++;
			arg->list_background.current = arg->list_background.current->next;
		}
		i++;
	}
	arg->item.item[arg->item.index] = NULL;
}
