/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:23:21 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/26 16:10:50 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	clr(t_spos *cur, t_spos *cur_n, t_spos *now)
{
	double	dist;
	double	dist_e;
	int		color_mov;
	int		ret;

	if (cur_n->color == cur->color)
		return (cur->color);
	else if (cur_n -> color > cur->color)
		color_mov = 1;
	else
		color_mov = -1;
	dist_e = sqrt((cur_n->s_x - cur->s_x) * (cur_n->s_x - cur->s_x) + \
	(cur_n->s_y - cur->s_y) * (cur_n->s_y - cur->s_y));
	dist = sqrt((now->s_x - cur->s_x) * (now->s_x - cur->s_x) + \
	(now->s_y - cur->s_y) * (now->s_y - cur->s_y));
	ret = cur->color + (color_mov * \
	(1 / abs_fdf(cur_n->color - cur->color)) * (dist / dist_e));
	return (ret);
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
