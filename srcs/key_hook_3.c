/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:33:11 by marvin            #+#    #+#             */
/*   Updated: 2023/02/25 20:33:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_translate(int keycode, t_mapinfo *map)
{
	if (keycode == KEY_W)
		press_w(map);
	else if (keycode == KEY_S)
		press_s(map);
	else if (keycode == KEY_A)
		press_a(map);
	else if (keycode == KEY_D)
		press_d(map);
}

void	press_w(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->p_ary[i].s_y -= 10.0;
		i++;
	}
}

void	press_s(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->p_ary[i].s_y += 10.0;
		i++;
	}
}

void	press_a(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->p_ary[i].s_x -= 10.0;
		i++;
	}
}

void	press_d(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->p_ary[i].s_x += 10.0;
		i++;
	}
}
