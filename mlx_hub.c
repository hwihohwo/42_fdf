/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:53:38 by marvin            #+#    #+#             */
/*   Updated: 2023/02/13 04:53:38 by marvin           ###   ########.fr       */
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
	img.img = mlx_new_image(mlx_ptr, WIN_WIDTH - 100, WIN_HEIGHT - 100);
	mlx_loop(mlx_ptr);
}