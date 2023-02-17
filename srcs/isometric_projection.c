/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:28:21 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/17 10:00:40 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_gap(t_mapinfo *map)
{
	int	i;
	int	x_max;
	int	y_max;

	i = 0;
	x_max = map->p_ary[i].s_x;
	y_max = map->p_ary[i].s_y;
	while (i < map->width * map->height)
	{
		if (map->p_ary[i].s_x > x_max)
			x_max = map->p_ary[i].s_x;
		if (map->p_ary[i].s_y > y_max)
			y_max = map->p_ary[i].s_y;
		i++;
	}
	while (x_max * map->gap < WIN_WIDTH - 100 \
	&& y_max * map->gap < WIN_HEIGHT - 100)
		map->gap++;
	i = 0;
	while (i < map->width * map->height)
	{
		map->p_ary[i].s_x *= map->gap;
		map->p_ary[i].s_y *= map->gap;
		i++;
	}
}

void	mov_pos(t_mapinfo *map, int x_min, int y_min)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (x_min < 0)
			map->p_ary[i].s_x -= x_min;
		if (y_min < 0)
			map->p_ary[i].s_y -= y_min;
		i++;
	}
}

void	adjust_pos(t_mapinfo *map)
{
	int	i;
	int	x_min;
	int	y_min;

	i = 0;
	x_min = map->p_ary[i].s_x;
	y_min = map->p_ary[i].s_y;
	while (i < map->width * map->height)
	{
		if (map->p_ary[i].s_x < x_min)
			x_min = map->p_ary[i].s_x;
		if (map->p_ary[i].s_y < y_min)
			y_min = map->p_ary[i].s_y;
		i++;
	}
	mov_pos(map, x_min, y_min);
}

void	projection(t_spos *pos, int i, int j, t_mapinfo *map)
{
	pos->s_x = (int)((j - i) * cos(30));
	pos->s_y = (int)((i + j) * sin(30) - map->alt_array[i][j]);
	pos->color = map->clr_ary[i][j];
	if (i < map->height - 1)
		pos->next_d = &(map->p_ary[j + map->width * (i + 1)]);
	else
		pos->next_d = 0;
	if (j < map->width - 1)
		pos->next_r = &(map->p_ary[(j + 1) + map->width * i]);
	else
		pos->next_r = 0;
}

void	init_projection(t_mapinfo *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	map->p_ary = ft_calloc(map->width * map->height, sizeof(t_spos));
	if (map->p_ary == 0)
		mapinfo_free_exit(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			projection(&map->p_ary[k++], i, j, map);
			j++;
		}
		i++;
	}
	adjust_pos(map);
	calc_gap(map);
}
