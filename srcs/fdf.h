/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:09:07 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/25 11:44:35 by marvin           ###   ########.fr       */
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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define PRESS_ESC 3

# define PI 3.14

typedef struct s_spos
{
	double				s_x;
	double				s_y;
	double				s_z;
	int					color;
	struct s_spos		*next_r;
	struct s_spos		*next_d;
}	t_spos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mapinfo
{
	char		*total;
	int			**alt_array;
	int			**clr_ary;
	t_spos		*p_ary;
	int			width;
	int			height;
	double		gap;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
}	t_mapinfo;

typedef struct s_mov
{
	int	x_mov;
	int	y_mov;
}	t_mov;

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
void	mapinfo_free_exit(t_mapinfo *map_info);

int		count_width(char *total);
int		count_height(char *total);
void	input_data(t_mapinfo *map_info);
void	control_map_info(t_mapinfo *map_info);

void	start_mlx(t_mapinfo *map_info);
void	init_image(t_mapinfo *map);

void	my_image_put_pixel(int x, int y, t_img *img, int color);
void	draw_line(t_mapinfo *map, void *mlx_ptr, void *win_ptr, t_img *img);
void	case_inclination_0_1(t_spos *cur, t_spos *cur_n, t_img *img);
void	case_inclination_2(t_spos *cur, t_spos *cur_n, t_img *img);

int		inclination_check(t_spos *cur, t_spos *cur_n);
void	mov_direction(t_mov *mov, t_spos *cur, t_spos *cur_n);
void	bresenhum(t_spos *cur, t_spos *cur_n, t_img *img);
void	bresenhum_reverse(t_spos *cur, t_spos *cur_n, t_img *img);
int		abs_fdf(int x);

void	calc_gap(t_mapinfo *map);
void	mov_pos(t_mapinfo *map, double x_min, double y_min);
void	adjust_pos(t_mapinfo *map);
void	projection(t_spos *pos, int i, int j, t_mapinfo *map);
void	init_projection(t_mapinfo *map);

void	z_rotate(double *x, double *y, double *z, double angle);
void	x_rotate(double *x, double *y, double *z, double angle);
void	y_rotate(double *x, double *y, double *z, double angle);

int		press_esc(int keycode, t_mapinfo *map);
int		press_red_cross(int keycode, int x, int y, t_mapinfo *map);

#endif