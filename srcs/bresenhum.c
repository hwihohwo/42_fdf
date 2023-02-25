/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:41:13 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/24 16:40:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	inclination_check(t_spos *cur, t_spos *cur_n)
{
	double	linear;

	if (cur_n->s_x == cur->s_x)
		return (0);
	else if (cur_n->s_y == cur->s_y)
		return (1);
	linear = (double)(cur_n->s_y - cur->s_y) / (double)(cur_n->s_x - cur->s_x);
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
	if (cur_n->s_y - cur->s_y >= 0)
		mov->mov_y = 1;
	else
		mov->mov_y = -1;
}

int	abs_fdf(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-1 * x);
}

void	bresenhum(t_spos *cur, t_spos *cur_n, t_img *img)
{
	int		w;
	int		h;
	t_mov	mov;
	int		f;
	t_spos	*start;

	start = cur;
	if (!inclination_check(cur, cur_n))
		return (bresenhum_reverse(cur, cur_n, img));
	w = abs_fdf((int)cur_n->s_x - (int)cur->s_x);
	h = abs_fdf((int)cur_n->s_y - (int)cur->s_y);
	mov_direction(&mov, cur, cur_n);
	f = 2 * h - w;
	while ((int)cur->s_x != (int)cur_n->s_x)
	{
		my_image_put_pixel((int)cur->s_x, (int)cur->s_y, img, clr(cur, cur_n, start));
		if (f < 0)
			f += 2 * h;
		else
		{
			cur->s_y += mov_y;
			f += 2 * (h - w);
		}
		cur->s_x += mov_x;
	}
}

void	bresenhum_reverse(t_spos *cur, t_spos *cur_n, t_img *img)
{
	int		w;
	int		h;
	t_mov	mov;
	int		f;
	t_spos	*start;

	start = cur;
	w = abs_fdf((int)cur_n->s_x - (int)cur->s_x);
	h = abs_fdf((int)cur_n->s_y - (int)cur->s_y);
	mov_direction(&mov, cur, cur_n);
	f = 2 * w - h;
	while ((int)cur->s_y != (int)cur_n->s_y)
	{
		my_image_put_pixel((int)cur->s_x, (int)cur->s_y, img, clr(cur, cur_n, start));
		if (f < 0)
			f += 2 * w;
		else
		{
			cur->s_x += mov_x;
			f += 2 * (w - h);
		}
		cur->s_y += mov_y;
	}
}
