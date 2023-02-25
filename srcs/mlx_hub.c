/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:53:38 by marvin            #+#    #+#             */
/*   Updated: 2023/02/25 11:47:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_image(t_mapinfo *map)
{
	if (map->img.img != 0)
		mlx_destory_image(map->mlx_ptr, map->img.img);
	map->img.img = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &(map->img.bits_per_pixel),\
	 &(map->img.line_length), &(map->img.endian));
}

void	start_mlx(t_mapinfo *map)
{
	map->mlx_ptr = mlx_init();
	map->mlx_win = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	init_projection(map);
	//draw_line(map);
	mlx_loop_hook(map->mlx_ptr, draw_line, map);
	mlx_hook(map->mlx_ptr, 3, 0, press_esc, map);
	mlx_hook(map->mlx_ptr, 17, 0, press_red_cross, map);
	mlx_loop(mlx_ptr);
}
