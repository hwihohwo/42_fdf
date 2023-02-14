/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:08:34 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/14 00:24:16 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map_info(t_mapinfo *map_info)
{
	map_info->total = 0;
	map_info->alt_array = 0;
	map_info->clr_ary = 0;
	map_info->width = 0;
	map_info->height = 0;
	map_info->gap = 0;
}

int	main(int argc, char *argv[])
{
	char		*format;
	t_mapinfo	map_info;

	if (argc != 2)
	{
		ft_printf("input one .fdf file");
		return (-1);
	}
	format = ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]));
	if (format == 0 || format[4] != '\0')
	{
		ft_printf("invalid file format");
		return (-1);
	}
	init_map_info(&map_info);
	map_info.total = open_file(argv[1]);
	control_map_info(&map_info);
	start_mlx(&map_info);
	return (0);
}
