/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_background_and_board_mlx_1.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:47:34 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/24 08:28:13 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_board_mlx_win(t_arg *arg, t_help_create *help_create)
{
	arg->board_mlx.height = help_create->height;
	arg->board_mlx.width = help_create->width;
	arg->board_mlx.mlx_win = mlx_new_window(arg->board_mlx.mlx,
			arg->board_mlx.width, arg->board_mlx.height, "Hello world!");
}
