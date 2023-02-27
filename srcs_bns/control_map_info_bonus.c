/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map_info_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:49:37 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 21:20:09 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	count_width(char *total)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (total[i] != '\n' && total[i] != '\0')
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

void	calloc_for_alt_clr_ary(t_mapinfo *map_info, int i)
{
	map_info->alt_array[i] = (int *)ft_calloc(map_info->width, sizeof(int));
	if (map_info->alt_array[i] == 0)
		mapinfo_free_exit(map_info);
	map_info->clr_ary[i] = (int *)ft_calloc(map_info->width, sizeof(int));
	if (map_info->clr_ary[i] == 0)
		mapinfo_free_exit(map_info);
}

void	input_data(t_mapinfo *map_info)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < map_info->height)
	{
		j = 0;
		calloc_for_alt_clr_ary(map_info, i);
		while (map_info->total[k] != '\n' && map_info->total[k])
		{
			map_info->alt_array[i][j] = ft_atoi(&map_info->total[k]);
			map_info->clr_ary[i][j++] = ft_strtol_16_fdf(&map_info->total[k]);
			while (map_info->total[k] == ' ')
				k++;
			while (ft_isalnum(map_info->total[k]) || map_info->total[k] == ',' \
			|| map_info->total[k] == '-' || map_info->total[k] == '+')
				k++;
			while (map_info->total[k] == ' ')
				k++;
		}
		k++;
	}
}

void	control_map_info(t_mapinfo *map_info)
{
	map_info->width = count_width(map_info->total);
	map_info->height = count_height(map_info->total);
	map_info->alt_array = (int **)ft_calloc(map_info->height, sizeof(int *));
	if (map_info->alt_array == 0)
		mapinfo_free_exit(map_info);
	map_info->clr_ary = (int **)ft_calloc(map_info->height, sizeof(int *));
	if (map_info->clr_ary == 0)
		mapinfo_free_exit(map_info);
	input_data(map_info);
}
