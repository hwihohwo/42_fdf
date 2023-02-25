/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:20:17 by marvin            #+#    #+#             */
/*   Updated: 2023/02/25 10:20:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press_button(int keycode, t_mapinfo *map)
{
	if (keycode == KEY_RIGHT)
		press_right(map);
	else if (keycode == KEY_LEFT)
		press_left(map);
	else if (keycode == KEY_UP)
		press_up(map);
	else if (keycode == KEY_DOWN)
		press_down(map);
	else if (keycode == KEY_O)
		press_o(map);
	else if (keycode == KEY_P)
		press_p(map);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A \
	|| keycode == KEY_D)
		press_rotate(keycode, map);
	else if (keycode == KEY_M || keycode == KEY_N)
		zoom_in_out(keycode, map);
}

int	press_esc(int keycode, t_mapinfo *map)
{
	if (keycode == PRESS_ESC)
	{
		mlx_destory_image(map->mlx_ptr, map->img.img);
		mlx_destory_window(map->mlx_ptr, map->mlx_win);
		mapinfo_free(map);
	}
	return (0);
}

int	press_red_cross(int keycode, int x, int y, t_mapinfo *map)
{
	keycode = 0;
	mlx_destory_image(map->mlx_ptr, map->img.img);
	mlx_destory_window(map->mlx_ptr, map->mlx_win);
	mapinfo_free(map);
	return (0);
}

void	press_right(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		z_rotate(&(map->p_ary[i].s_x), &(map->p_ary[i].s_y), \
		&(map->p_ary[i].s_z), 5);
		i++;
	}
}

void	press_left(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		z_rotate(&(map->p_ary[i].s_x), &(map->p_ary[i].s_y), \
		&(map->p_ary[i].s_z), -5);
		i++;
	}
}
