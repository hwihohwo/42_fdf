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