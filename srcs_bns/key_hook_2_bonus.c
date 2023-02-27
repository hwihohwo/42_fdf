/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:45:58 by marvin            #+#    #+#             */
/*   Updated: 2023/02/25 18:45:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	press_up(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		x_rotate(&(map->p_ary[i].s_x), &(map->p_ary[i].s_y), \
		&(map->p_ary[i].s_z), 5);
		i++;
	}
}

void	press_down(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		x_rotate(&(map->p_ary[i].s_x), &(map->p_ary[i].s_y), \
		&(map->p_ary[i].s_z), -5);
		i++;
	}
}

void	press_o(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		y_rotate(&(map->p_ary[i].s_x), &(map->p_ary[i].s_y), \
		&(map->p_ary[i].s_z), -5);
		i++;
	}
}

void	press_p(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		y_rotate(&(map->p_ary[i].s_x), &(map->p_ary[i].s_y), \
		&(map->p_ary[i].s_z), 5);
		i++;
	}
}

void	zoom_in_out(int keycode, t_mapinfo *map)
{
	int	i;

	i = 0;
	divide_gap(map);
	if (keycode == KEY_M)
		map->gap += 0.3;
	else if (keycode == KEY_N)
	{
		map->gap -= 0.3;
		if (map->gap < 1.0)
			map->gap += 0.3;
	}
	while (i < map->height * map->width)
	{
		map->p_ary[i].s_x *= map->gap;
		map->p_ary[i].s_y *= map->gap;
		map->p_ary[i].s_z *= map->gap;
		i++;
	}
}
