/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:53:38 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 19:14:01 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_image(t_mapinfo *map)
{
	if (map->img.img != 0)
		mlx_destroy_image(map->mlx_ptr, map->img.img);
	map->img.img = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &(map->img.bits_per_pixel), \
	&(map->img.line_length), &(map->img.endian));
}

void	start_mlx(t_mapinfo *map)
{
	map->mlx_ptr = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	init_projection(map);
	mlx_hook(map->mlx_win, 2, 0, &press_button, map);
	mlx_hook(map->mlx_win, 17, 0, &press_red_cross, map);
	mlx_loop_hook(map->mlx_ptr, &draw_line, map);
	mlx_loop(map->mlx_ptr);
}
