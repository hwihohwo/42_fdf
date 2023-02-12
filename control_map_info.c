/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:49:37 by marvin            #+#    #+#             */
/*   Updated: 2023/02/12 19:49:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(char *total)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (total[i])
	{
		if (ft_isdigit(total[i]))
		{
			ret++;
			while (total[i] != ' ' && total[i] != '\n' && total[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

int	count_height(char *total)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (total[i])
	{
		if (ft_isdigit(total[i]))
		{
			ret++;
			while (total[i] != '\n' && total[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

void	input_data(t_mapinfo *map_info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < map_info->height)
	{
		j = 0;
		map_info->alt_array[i] = (int *)ft_calloc(map_info->width, sizeof(int));
		if (map_info->alt_array[i] == NULL)
			malloc_error_exit(map_info);
		map_info->color_array[i] = (int *)ft_calloc(map_info->width, sizeof(int));
		if (map_info->color_array[i] == NULL)
			malloc_error_exit(map_info);
		while (map_info->total[k] != '\n' && map_info->total[k])
		{
			map_info->alt_array[i][j] = ft_atoi(&map_info->total[k]);
			map_info->color_array[i][j++] = ft_strtol_16_fdf(&map_info->total[k]);
			while (map_info->total[k] != ' ' && map_info->total[k])
				k++;
		}
		i++;
	}
}

void	control_map_info(t_mapinfo *map_info)
{
	map_info->width = count_width(map_info->total);
	map_info->height = count_height(map_info->total);
	map_info->alt_array = (int **)ft_calloc(map_info->height, sizeof(int *));
	if (map_info->alt_array == NULL)
		malloc_error_exit(map_info);
	map_info->color_array = (int **)ft_calloc(map_info->height, sizeof(int *));
	if (map_info->color_array == NULL)
		malloc_error_exit(map_info);
	input_data(map_info);
}