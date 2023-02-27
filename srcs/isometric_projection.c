/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:28:21 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 21:17:04 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_gap(t_mapinfo *map)
{
	int		i;
	double	x_max;
	double	z_max;

	i = 0;
	x_max = map->p_ary[i].s_x;
	z_max = map->p_ary[i].s_z;
	while (i < map->width * map->height)
	{
		if (x_max < map->p_ary[i].s_x)
			x_max = map->p_ary[i].s_x;
		if (z_max < map->p_ary[i].s_z)
			z_max = map->p_ary[i].s_z;
		i++;
	}
	while (x_max * map->gap < WIN_WIDTH - 100 && \
	z_max * map->gap < WIN_HEIGHT - 100)
		map->gap += 0.1;
}

void	mov_pos(t_mapinfo *map, double x_min, double z_min)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (x_min <= 0)
			map->p_ary[i].s_x += (-1) * x_min + 1;
		if (z_min <= 0)
			map->p_ary[i].s_z += (-1) * z_min + 1;
		i++;
	}
	calc_gap(map);
	i = 0;
	while (i < map->width * map->height)
	{
		map->p_ary[i].s_x *= map->gap;
		map->p_ary[i].s_z *= map->gap;
		i++;
	}
}

void	adjust_pos(t_mapinfo *map)
{
	int		i;
	double	x_min;
	double	z_min;

	i = 0;
	x_min = map->p_ary[i].s_x;
	z_min = map->p_ary[i].s_z;
	while (i < map->width * map->height)
	{
		if (map->p_ary[i].s_x < x_min)
			x_min = map->p_ary[i].s_x;
		if (map->p_ary[i].s_z < z_min)
			z_min = map->p_ary[i].s_z;
		i++;
	}
	mov_pos(map, x_min, z_min);
}

void	projection(t_spos *pos, int i, int j, t_mapinfo *map)
{
	double	x;
	double	y;
	double	z;

	x = (double)j;
	y = (double)i;
	z = (double)map->alt_array[i][j] * (-1);
	z_rotate(&x, &y, &z, -45);
	x_rotate(&x, &y, &z, 35.2);
	pos->s_x = x;
	pos->s_y = y;
	pos->s_z = z;
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
}
