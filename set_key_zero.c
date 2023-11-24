/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_key_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:09:55 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/11 14:10:44 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_keypress_to_left(t_data *data)
{
	if (data->list_player->left > 0)
	{
		data->list_player->right = 0;
		data->list_player->up = 0;
		data->list_player->down = 0;
	}
}

void	set_keypress_to_right(t_data *data)
{
	if (data->list_player->right > 0)
	{
		data->list_player->left = 0;
		data->list_player->up = 0;
		data->list_player->down = 0;
	}
}

void	set_keypress_to_up(t_data *data)
{
	if (data->list_player->up > 0)
	{
		data->list_player->left = 0;
		data->list_player->right = 0;
		data->list_player->down = 0;
	}
}

void	set_keypress_to_down(t_data *data)
{
	if (data->list_player->down > 0)
	{
		data->list_player->left = 0;
		data->list_player->up = 0;
		data->list_player->right = 0;
	}
}
