/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:12:29 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/13 13:30:30 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_list_line *list_line)
{
	int	error_rec;
	int	length_bf_line;

	error_rec = 0;
	length_bf_line = list_line->head->length_str;
	list_line->current = list_line->head;
	while (list_line->current)
	{
		length_bf_line = list_line->current->length_str;
		if (list_line->current->next)
		{
			if (length_bf_line != list_line->current->next->length_str)
				error_rec = 1;
		}
		list_line->current = list_line->current->next;
	}
	if (error_rec)
	{
		write(2, "Error map could rectangular\n", 23);
		free_list_line(list_line);
		exit(1);
	}
}
