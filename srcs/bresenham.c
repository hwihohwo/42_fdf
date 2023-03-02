/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:41:13 by seonghwc          #+#    #+#             */
/*   Updated: 2023/03/02 15:42:58 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_input_w_h(t_spos *cur, t_spos *cur_n, int *w, int *h)
{
	double	linear;

	*w = abs_fdf((int)cur_n->s_x - (int)cur->s_x);
	*h = abs_fdf((int)cur_n->s_z - (int)cur->s_z);
	if (cur_n->s_x == cur->s_x)
		return (0);
	else if (cur_n->s_z == cur->s_z)
		return (1);
	linear = (double)(cur_n->s_z - cur->s_z) / (double)(cur_n->s_x - cur->s_x);
	if (linear < 0)
		linear *= -1;
	if (linear < 1)
		return (1);
	else
		return (0);
}

void	mov_direction(t_mov *mov, t_spos *cur, t_spos *cur_n)
{
	if (cur_n->s_x - cur->s_x >= 0)
		mov->x_mov = 1;
	else
		mov->x_mov = -1;
	if (cur_n->s_z - cur->s_z >= 0)
		mov->z_mov = 1;
	else
		mov->z_mov = -1;
}

int	abs_fdf(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-1 * x);
}

void	bresenham(t_spos *cur, t_spos *cur_n, t_img *img, t_mapinfo *map)
{
	int		w;
	int		h;
	t_mov	mov;
	int		f;
	t_spos	now;

	now.s_x = cur->s_x;
	now.s_z = cur->s_z;
	if (!check_input_w_h(cur, cur_n, &w, &h))
		return (bresenham_rev(cur, cur_n, img, map));
	mov_direction(&mov, cur, cur_n);
	f = 2 * h - w;
	while ((int)now.s_x != (int)cur_n->s_x)
	{
		my_image_put_pixel(&now, img, clr(cur, cur_n, &now), map);
		if (f < 0)
			f += 2 * h;
		else
		{
			now.s_z += mov.z_mov;
			f += 2 * (h - w);
		}
		now.s_x += mov.x_mov;
	}
}

void	bresenham_rev(t_spos *cur, t_spos *cur_n, t_img *img, t_mapinfo *map)
{
	int		w;
	int		h;
	t_mov	mov;
	int		f;
	t_spos	now;

	now.s_x = cur->s_x;
	now.s_z = cur->s_z;
	w = abs_fdf((int)cur_n->s_x - (int)cur->s_x);
	h = abs_fdf((int)cur_n->s_z - (int)cur->s_z);
	mov_direction(&mov, cur, cur_n);
	f = 2 * w - h;
	while ((int)now.s_z != (int)cur_n->s_z)
	{
		my_image_put_pixel(&now, img, clr(cur, cur_n, &now), map);
		if (f < 0)
			f += 2 * w;
		else
		{
			now.s_x += mov.x_mov;
			f += 2 * (w - h);
		}
		now.s_z += mov.z_mov;
	}
}
