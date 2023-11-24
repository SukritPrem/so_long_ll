/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:16:13 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 13:29:53 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_create_map(t_list_line *list_line, t_arg *arg, int error_case,
		char ***map)
{
	if (error_case == ERROR_MALLOC_MAP)
	{
		write(2, "Error malloc map\n", 18);
		free_list_line(list_line);
		exit(1);
	}
	else if (error_case == ERROR_MALLOC_MAP_I)
	{
		write(2, "Error malloc map[i]\n", 21);
		free_list_line(list_line);
		free_map(map);
		exit(1);
	}
}

void	set_arg(char **map, t_arg *arg, int i, int j)
{
	if (map[i][j] == 'P')
	{
		arg->count_player++;
		arg->i_x = j;
		arg->i_y = i;
	}
	else if (map[i][j] == 'C')
		arg->count_all_item++;
	else if (map[i][j] == 'E')
		arg->count_all_exit++;
	else if (map[i][j] != '1' && map[i][j] != '0')
		arg->have_dif_char++;
}

void	set_arg_w_h(char **map, int i, t_list_line *list_line, t_arg *arg)
{
	map[i] = NULL;
	arg->width_map = list_line->head->length_str;
	arg->height_map = list_line->member_in_list;
}

void	set_plus_i_and_next_node(t_init_map *data, t_list_line *list_line)
{
	data->map[data->i][data->j] = '\0';
	list_line->current = list_line->current->next;
	data->i++;
}

char	**init_map(t_list_line *list_line, t_arg *arg)
{
	t_init_map	data;

	data.map = malloc(sizeof(char *) * (list_line->member_in_list + 1));
	if (data.map == NULL)
		error_create_map(list_line, arg, ERROR_MALLOC_MAP, &data.map);
	list_line->current = list_line->head;
	data.i = 0;
	data.j = 0;
	while (data.i < list_line->member_in_list)
	{
		data.map[data.i] = malloc(sizeof(char) * (list_line->current->length_str
					+ 1));
		if (data.map[data.i] == NULL)
			error_create_map(list_line, arg, ERROR_MALLOC_MAP_I, &data.map);
		data.j = 0;
		while (data.j < list_line->current->length_str)
		{
			data.map[data.i][data.j] = list_line->current->line[data.j];
			set_arg(data.map, arg, data.i, data.j);
			data.j++;
		}
		set_plus_i_and_next_node(&data, list_line);
	}
	set_arg_w_h(data.map, data.i, list_line, arg);
	return (data.map);
}
