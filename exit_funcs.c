/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:05:04 by marvin            #+#    #+#             */
/*   Updated: 2023/02/13 00:05:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_error_exit(void)
{
	perror(0);
	exit(1);
}

void	map_error_exit(char **line_sep, char *line, char *total)
{
	free_string_array(line_sep);
	if (line != NULL)
		free(line);
	if (total != NULL)
		free(total);
	ft_printf("invalid map");
	exit(1);
}

void	malloc_error_exit(t_mapinfo *map_info)
{
	int	i;

	i = 0;
	free(map_info->total);
	if (map_info->alt_array != NULL)
	{
		while (map_info->alt_array[i])
			free(map_info->altarray[i++]);
		free(map_info->alt_array);
	}
	i = 0;
	if (map_info->color_array != NULL)
	{
		while (map_info->color_array[i])
			free(map_info->color_array[i++]);
		free(map_info->color_array);
	}
	perror(0);
	exit(1);
}