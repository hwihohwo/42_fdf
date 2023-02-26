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

int	press_button(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		press_esc(param);
	else if (keycode == KEY_RIGHT)
		press_right(param);
	else if (keycode == KEY_LEFT)
		press_left(param);
	else if (keycode == KEY_UP)
		press_up(param);
	else if (keycode == KEY_DOWN)
		press_down(param);
	else if (keycode == KEY_O)
		press_o(param);
	else if (keycode == KEY_P)
		press_p(param);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A \
	|| keycode == KEY_D)
		press_translate(keycode, param);
	else if (keycode == KEY_M || keycode == KEY_N)
		zoom_in_out(keycode, param);
	return (0);
}

int	press_esc(t_mapinfo *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.img);
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	mapinfo_free(map);
	return (0);
}

int	press_red_cross(int keycode, int x, int y, void *param)
{
	keycode = 0;
	x = 0;
	y = 0;
	mlx_destroy_image(((t_mapinfo *)param)->mlx_ptr, \
	((t_mapinfo *)param)->img.img);
	mlx_destroy_window(((t_mapinfo *)param)->mlx_ptr, \
	((t_mapinfo *)param)->mlx_win);
	mapinfo_free(param);
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
