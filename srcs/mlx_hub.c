/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:53:38 by marvin            #+#    #+#             */
/*   Updated: 2023/02/23 17:31:49 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_mlx(t_mapinfo *map_info)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	img.img = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), \
	&(img.line_length), &(img.endian));
	init_projection(map_info);
	draw_line(map_info, mlx_ptr, mlx_win, &img);
	mlx_loop(mlx_ptr);
}
