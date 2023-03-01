/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:53:38 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 15:42:58 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_image(t_mapinfo *map)
{
	if (map->img.img != 0)
		mlx_destroy_image(map->mlx_ptr, map->img.img);
	map->img.img = mlx_new_image(map->mlx_ptr, map->map_width, map->map_height);
	map->img.addr = mlx_get_data_addr(map->img.img, &(map->img.bits_per_pixel), \
	&(map->img.line_length), &(map->img.endian));
}

void	start_mlx(t_mapinfo *map)
{
	map->mlx_ptr = mlx_init();
	init_projection(map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, \
	map->map_width, map->map_height, "fdf");
	mlx_loop_hook(map->mlx_ptr, &draw_line, map);
	mlx_hook(map->mlx_win, 2, 0, &press_button, map);
	mlx_hook(map->mlx_win, 17, 0, &press_red_cross, map);
	mlx_loop(map->mlx_ptr);
}
