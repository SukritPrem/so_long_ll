/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:39:34 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/13 14:39:57 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(t_exit *player, t_mlx *board_mlx)
{
	mlx_destroy_image(board_mlx, player->head->picture->img);
	free(player->head->picture);
	free(player->head);
}
