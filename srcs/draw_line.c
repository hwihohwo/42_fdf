/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:23:21 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/23 17:31:28 by seonghwc         ###   ########.fr       */
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

void	case_inclination_0_1(t_spos *cur, t_spos *cur_n, t_img *img)
{
	int	mov;

	if ((int)cur->s_x == (int)cur_n->s_x && (int)cur->s_y == (int)cur_n->s_y)
		return ;
	if ((int)cur->s_x == (int)cur_n->s_x)
	{
		if ((int)cur->s_y < (int)cur_n->s_y)
			mov = 1;
		else
			mov = -1;
		while ((int)cur->s_y != (int)cur_n->s_y)
		{
			my_image_put_pixel((int)cur->s_x, (int)cur->s_y, img, 0xFFFFFF);
			cur->s_y += mov;
		}
	}
	else if ((int)cur->s_y == (int)cur_n->s_y)
		case_inclination_2(cur, cur_n, img);
}

void	case_inclination_2(t_spos *cur, t_spos *cur_n, t_img *img)
{
	int	mov;

	if ((int)cur->s_x < (int)cur_n->s_x)
		mov = 1;
	else
		mov = -1;
	while ((int)cur->s_x != (int)cur_n->s_x)
	{
		my_image_put_pixel((int)cur->s_x, (int)cur->s_y, img, 0xFFFFFF);
		cur->s_x += mov;
	}
}

void	draw_line(t_mapinfo *map, void *mlx_ptr, void *win_ptr, t_img *img)
{
	int	i;

	i = 0;
	while (i < map->height * map->width)
	{
		if (map->p_ary[i].next_r != 0)
		{
			if (map->p_ary[i].s_x == map->p_ary[i].next_r->s_x || \
			map->p_ary[i].s_y == map->p_ary[i].next_r->s_y)
				case_inclination_0_1(&map->p_ary[i], map->p_ary[i].next_r, img);
			else
				bresenhum(&map->p_ary[i], map->p_ary[i].next_r, img);
		}
		if (map->p_ary[i].next_d != 0)
		{
			if (map->p_ary[i].s_x == map->p_ary[i].next_d->s_x || \
			map->p_ary[i].s_y == map->p_ary[i].next_d->s_y)
				case_inclination_0_1(&map->p_ary[i], map->p_ary[i].next_d, img);
			else
				bresenhum(&map->p_ary[i], map->p_ary[i].next_d, img);
		}
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);
}
