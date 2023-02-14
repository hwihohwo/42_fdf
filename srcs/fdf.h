/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:09:07 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/14 01:35:37 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN_WIDTH 1900
# define WIN_HEIGHT 1080

typedef struct s_mapinfo
{
	char	*total;
	int		**alt_array;
	int		**clr_ary;
	int		width;
	int		height;
	int		gap;
}	t_mapinfo;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_spos
{
	int	s_x;
	int	s_y;
	int	color;
}	t_spos;

void	init_map_info(t_mapinfo *map_info);

int		ft_strtol_get_val(char c);
int		ft_strtol_16_fdf(char *str);

char	*open_file(char *argv);
void	check_line(char *line, int *col_num, char *total);
void	free_string_array(char **line_sep);
char	*join_line(char *total, char *line);

int		error_check(char *line);
int		color_error_check(char *line);

void	open_error_exit(void);
void	map_error_exit(char **line_sep, char *line, char *total);
void	malloc_error_exit(t_mapinfo *map_info);

int		count_width(char *total);
int		count_height(char *total);
void	input_data(t_mapinfo *map_info);
void	control_map_info(t_mapinfo *map_info);

#endif