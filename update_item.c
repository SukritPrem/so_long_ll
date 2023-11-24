/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:16:40 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:10:39 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_data_update_item(t_update_item *data_i, t_data *data)
{
	data_i->px = data->list_player->head->pos_x;
	data_i->py = data->list_player->head->pos_y;
	data_i->left = data->list_player->left;
	data_i->right = data->list_player->right;
	data_i->up = data->list_player->up;
	data_i->down = data->list_player->down;
}

void	conditon_update_item(t_update_item *d_i, t_data *data)
{
	if (d_i->i_x == d_i->px - 100 && d_i->i_y == d_i->py && d_i->left > 1)
		update_item_left(data, d_i->i);
	else if (d_i->i_x == d_i->px + 100 && d_i->i_y == d_i->py && d_i->right > 1)
		update_item_right(data, d_i->i);
	else if (d_i->i_x == d_i->px && d_i->i_y == d_i->py - 100 && d_i->up > 1)
		update_item_up(data, d_i->i);
	else if (d_i->i_x == d_i->px && d_i->i_y == d_i->py + 100 && d_i->down > 1)
		update_item_down(data, d_i->i);
}

void	update_item(t_data *data)
{
	t_update_item	d_i;

	set_data_update_item(&d_i, data);
	if (data->list_item->item != NULL)
	{
		d_i.i = 0;
		while (d_i.i < data->list_item->count_all_item)
		{
			d_i.i_x = data->list_item->item[d_i.i]->pos_x;
			d_i.i_y = data->list_item->item[d_i.i]->pos_y;
			if (data->list_item->item[d_i.i]->picture != NULL)
				conditon_update_item(&d_i, data);
			d_i.i++;
		}
	}
}
