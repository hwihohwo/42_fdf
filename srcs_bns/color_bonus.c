/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:07:36 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 21:24:18 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_clr(t_clr *clr, t_spos *cur)
{
	clr->r = (cur->color >> 16) & 0xFF;
	clr->g = (cur->color >> 8) & 0xFF;
	clr->b = cur->color & 0xFF;
}

int	clr(t_spos *cur, t_spos *cur_n, t_spos *now)
{
	double	dist;
	double	dist_e;
	t_clr	clr_next;
	t_clr	clr_orig;

	if (cur->color == cur_n->color)
		return (cur->color);
	init_clr(&clr_orig, cur);
	init_clr(&clr_next, cur_n);
	dist_e = sqrt((cur_n->s_x - cur->s_x) * (cur_n->s_x - cur->s_x) + \
	(cur_n->s_z - cur->s_z) * (cur_n->s_z - cur->s_z));
	dist = sqrt((now->s_x - cur->s_x) * (now->s_x - cur->s_x) + \
	(now->s_z - cur->s_z) * (now->s_z - cur->s_z));
	return (\
	(calc_color((clr_orig.r), clr_next.r - clr_orig.r, dist / dist_e) << 16) | \
	(calc_color((clr_orig.g), clr_next.g - clr_orig.g, dist / dist_e) << 8) | \
	calc_color((clr_orig.b), clr_next.b - clr_orig.b, dist / dist_e));
}

int	calc_color(int color, int color_diff, double dist_ratio)
{
	int	ret;
	int	color_mov;

	if (color_diff > 0)
		color_mov = 1;
	else
		color_mov = -1;
	ret = color + (color_mov * abs_fdf(color_diff) * dist_ratio);
	return (ret);
}
