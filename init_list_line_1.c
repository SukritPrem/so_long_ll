/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_line_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:56:19 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/17 18:59:20 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber_file(char *file_name)
{
	char	*type;
	int		i;

	type = ".ber";
	i = ft_strlen(file_name) - 4;
	if (i <= 0)
		error_in_list_line(0, NULL, ERROR_OPEN_FILE);
	else if (ft_strncmp(&file_name[i], type, 4) && file_name[i])
		error_in_list_line(0, NULL, ERROR_OPEN_FILE);
}
