/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:19:03 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 13:21:00 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_create_list_wall(t_arg *arg, int case_error)
{
	if (case_error == ERROR_CREATE_HEAD_LIST_WALL)
	{
		write(2, "Error malloc head list wall\n", 29);
		free_list_background(&arg->list_background, arg->board_mlx.mlx);
		free_list_background(&arg->list_wall, arg->board_mlx.mlx);
		free_map(&arg->map);
		exit(1);
	}
	else if (case_error == ERROR_CREATE_CLONE_LIST_WALL)
	{
		write(2, "Error malloc clone list wall\n", 30);
		free_list_background(&arg->list_background, arg->board_mlx.mlx);
		free_list_background(&arg->list_wall, arg->board_mlx.mlx);
		free_map(&arg->map);
		exit(1);
	}
}

void	create_head_list_wall(t_arg *arg)
{
	arg->list_wall.head = create_list_background(\
			arg->list_background.current->pos_x, \
			arg->list_background.current->pos_y, \
			'W', arg->board_mlx.mlx);
	if (arg->list_wall.head == NULL)
		error_create_list_wall(arg, ERROR_CREATE_HEAD_LIST_WALL);
	arg->list_wall.current = arg->list_wall.head;
}

void	create_clone_list_wall(t_arg *arg)
{
	arg->list_wall.clone = create_list_background(\
			arg->list_background.current->pos_x, \
			arg->list_background.current->pos_y, \
			'W', arg->board_mlx.mlx);
	if (arg->list_wall.clone == NULL)
		error_create_list_wall(arg, ERROR_CREATE_CLONE_LIST_WALL);
	arg->list_wall.current->next = arg->list_wall.clone;
	arg->list_wall.current = arg->list_wall.clone;
}

void	init_list_wall(t_arg *arg)
{
	int	i;
	int	j;

	arg->list_wall.head = NULL;
	arg->list_background.current = arg->list_background.head;
	i = 0;
	j = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == '1')
			{
				if (arg->list_wall.head == NULL)
					create_head_list_wall(arg);
				else
					create_clone_list_wall(arg);
			}
			arg->list_background.current = arg->list_background.current->next;
			j++;
		}
		i++;
	}
}
