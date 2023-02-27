/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:23:21 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 21:20:10 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_image_put_pixel(int x, int y, t_img *img, int color)
{
	char	*dst;

	if (0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_length + \
		x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	divide_gap(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->height * map->width)
	{
		map->p_ary[i].s_x /= map->gap;
		map->p_ary[i].s_y /= map->gap;
		map->p_ary[i].s_z /= map->gap;
		i++;
	}
}

int	draw_line(t_mapinfo *map)
{
	int	i;

	i = 0;
	init_image(map);
	while (i < map->height * map->width)
	{
		if (map->p_ary[i].next_r != 0)
			bresenhum(&map->p_ary[i], map->p_ary[i].next_r, &(map->img));
		if (map->p_ary[i].next_d != 0)
			bresenhum(&map->p_ary[i], map->p_ary[i].next_d, &(map->img));
		i++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->img.img, 0, 0);
	return (0);
}
