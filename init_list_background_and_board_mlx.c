/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_background_and_board_mlx.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:17:46 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/13 15:47:56 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_board_mlx(t_arg *arg)
{
	arg->board_mlx.mlx = mlx_init();
	arg->board_mlx.width = 0;
	arg->board_mlx.height = 0;
}

void	set_zero_help_create(t_help_create *help_create)
{
	help_create->i = 0;
	help_create->j = 0;
	help_create->width = 0;
	help_create->height = 0;
	help_create->width_max = 0;
}

void	create_node_list_back_first(t_arg *arg, t_help_create *help_create)
{
	arg->list_background.head = create_list_background(0, 0, 'B',
			arg->board_mlx.mlx);
	if (arg->list_background.head == NULL)
	{
		free_map(&arg->map);
		exit(1);
	}
	help_create->width = help_create->width
		+ arg->list_background.head->picture->width;
	arg->list_background.current = arg->list_background.head;
}

void	create_node_list_back_second(t_arg *arg, t_help_create *help_create)
{
	if (help_create->width > help_create->width_max)
		help_create->width_max = help_create->width;
	arg->list_background.clone = create_list_background(help_create->width,
			help_create->height, 'B', arg->board_mlx.mlx);
	if (arg->list_background.clone == NULL)
	{
		free_list_background(&arg->list_background, arg->board_mlx.mlx);
		free_map(&arg->map);
		exit(1);
	}
	help_create->width = help_create->width
		+ arg->list_background.current->picture->width;
	arg->list_background.current->next = arg->list_background.clone;
	arg->list_background.current = arg->list_background.clone;
}

void	init_list_background_and_board_mlx(t_arg *arg)
{
	t_help_create	help_create;

	init_board_mlx(arg);
	arg->list_background.head = NULL;
	set_zero_help_create(&help_create);
	arg->list_background.current = arg->list_background.head;
	while (arg->map[help_create.i])
	{
		help_create.width = 0;
		help_create.j = 0;
		while (arg->map[help_create.i][help_create.j])
		{
			if (arg->list_background.head == NULL)
				create_node_list_back_first(arg, &help_create);
			else
				create_node_list_back_second(arg, &help_create);
			help_create.j++;
		}
		help_create.height = help_create.height
			+ arg->list_background.current->picture->height;
		help_create.i++;
	}
	init_board_mlx_win(arg, &help_create);
}
