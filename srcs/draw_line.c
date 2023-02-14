/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:23:21 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/14 07:57:49 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_image_put_pixel(int x, int y, t_img *img, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)dest = color;
}

void	calc_gap(t_mapinfo *map_info)
{
	map_info->gap = 1;
	while ((map_info->gap * (map_info->width - 1) < WIN_WIDTH - 100) && \
	(map_info->gap * (map_info->height - 1) < WIN_HEIGHT - 100))
		map_info->gap++;
}

void	draw_line(t_mapinfo *map_info, void *mlx_ptr, void *win_ptr, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	calc_gap(map_info);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	while (i < map_info->height - 1)
	{
		j = 0;
		while (j < map_info->width - 1)
		{
			draw_line_2(i, j, map_info, img);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 100, 100);
}

void	draw_line_2(int i, int j, t_mapinfo *map_info, t_img *img)
{
	t_spos	cur;
	t_spos	cur_r;
	t_spos	cur_d;

	init_cur_and_projection(&cur, i, j, map_info);
	if (j < map_info->width - 1)
		init_cur_and_projection(&cur_r, i, j + 1, map_info);
	if (i < map_info->height - 1)
		init_cur_and_projection(&cur_d, i + 1, j, map_info);
	if (j < map_info->width - 1)
		bresenhum(&cur, &cur_r, img);
	if (i < map_info->height - 1)
		bresenhum(&cur, &cur_d, img);
}

void	init_cur_and_projection(t_spos *cur, int i, int j, t_mapinfo *map_info)
{
	int	temp_x;
	int	temp_y;
	int	temp_z;

	temp_x = i * map_info->gap;
	temp_y = j * map_info->gap;
	temp_z = map_info->alt_array[i][j] * map_info->gap;
	cur->s_x = (int)((temp_x - temp_y) * cos(30));
	cur->s_y = (int)((temp_x + temp_y) * sin(30) + temp_z);
	cur->color = map_info->clr_ary[i][j];
}
