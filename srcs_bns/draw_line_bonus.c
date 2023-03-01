/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:23:21 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/01 14:05:21 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_image_put_pixel(t_spos *now, t_img *img, int color, t_mapinfo *map)
{
	char	*dst;
	int		x;
	int		z;

	x = (int)now->s_x;
	z = (int)now->s_z;
	if (0 < x && x < map->map_width && 0 < z && z < map->map_height)
	{
		dst = img->addr + (z * img->line_length + \
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
			bresenhum(&map->p_ary[i], map->p_ary[i].next_r, &(map->img), map);
		if (map->p_ary[i].next_d != 0)
			bresenhum(&map->p_ary[i], map->p_ary[i].next_d, &(map->img), map);
		i++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->img.img, 0, 0);
	return (0);
}
