/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:05:04 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 00:55:43 by seonghwc         ###   ########.fr       */
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
	if (line != 0)
		free(line);
	if (total != 0)
		free(total);
	ft_printf("invalid map");
	exit(1);
}

void	mapinfo_free_exit(t_mapinfo *map_info)
{
	int	i;

	i = 0;
	free(map_info->total);
	if (map_info->alt_array != 0)
	{
		while (map_info->alt_array[i])
			free(map_info->alt_array[i++]);
		free(map_info->alt_array);
	}
	i = 0;
	if (map_info->clr_ary != 0)
	{
		while (map_info->clr_ary[i])
			free(map_info->clr_ary[i++]);
		free(map_info->clr_ary);
	}
	if (map_info->total != 0)
		free(map_info->total);
	if (map_info->p_ary != 0)
		free(map_info->p_ary);
	perror(0);
	exit(1);
}
