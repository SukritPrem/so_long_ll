/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:14:19 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/21 13:30:17 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_in_list_line(int fd, t_list_line *list_line, int case_error)
{
	if (case_error == ERROR_OPEN_FILE)
	{
		write(2, "Error open file \n", 18);
		exit(1);
	}
	else if (case_error == ERROR_MALLOC_HEAD_LISTLINE)
	{
		close(fd);
		write(2, "Error malloc list line\n", 24);
		exit(1);
	}
	else if (case_error == ERROR_NULL_STRING)
	{
		close(fd);
		write(2, "Error don't have string!!!\n", 24);
		free(list_line->head);
		exit(1);
	}
	else if (case_error == ERROR_MALLOC_LISTLINE)
	{
		close(fd);
		write(2, "Error malloc list line\n", 24);
		free_list_line(list_line);
		exit(1);
	}
}

void	count_str_list_head(t_list_line *list_line)
{
	list_line->head->length_str = 0;
	while (list_line->head->line[list_line->head->length_str])
	{
		if (list_line->head->line[list_line->head->length_str] == '\n')
			break ;
		list_line->head->length_str++;
	}
}

void	count_str_list_clone_head(t_list_line *list_line)
{
	list_line->clone->length_str = 0;
	while (list_line->clone->line[list_line->clone->length_str])
	{
		if (list_line->clone->line[list_line->clone->length_str] == '\n')
			break ;
		list_line->clone->length_str++;
	}
	list_line->clone->next = NULL;
	list_line->member_in_list = list_line->member_in_list + 1;
	list_line->current->next = list_line->clone;
	list_line->current = list_line->clone;
}

void	create_list_head(int fd, t_list_line *list_line, char **argv)
{
	if (fd < 0)
		error_in_list_line(fd, list_line, ERROR_OPEN_FILE);
	list_line->head = malloc(sizeof(t_line));
	if (list_line->head == NULL)
		error_in_list_line(fd, list_line, ERROR_MALLOC_HEAD_LISTLINE);
	list_line->head->line = NULL;
	list_line->head->line = get_next_line(fd);
	if (list_line->head->line == NULL)
		error_in_list_line(fd, list_line, ERROR_NULL_STRING);
	count_str_list_head(list_line);
}

void	init_list_line(char **argv, t_list_line *list_line)
{
	int	fd;

	check_ber_file(argv[1]);
	fd = open(argv[1], O_RDONLY);
	create_list_head(fd, list_line, argv);
	list_line->member_in_list = 1;
	list_line->current = list_line->head;
	while (list_line->current->line)
	{
		list_line->clone = malloc(sizeof(t_line));
		if (list_line->clone == NULL)
			error_in_list_line(fd, list_line, ERROR_NULL_STRING);
		list_line->clone->line = get_next_line(fd);
		if (list_line->clone->line == NULL)
		{
			close(fd);
			free(list_line->clone->line);
			free(list_line->clone);
			break ;
		}
		count_str_list_clone_head(list_line);
	}
	close(fd);
	check_rectangular(list_line);
}
