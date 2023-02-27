/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:09:07 by seonghwc          #+#    #+#             */
/*   Updated: 2023/02/27 19:13:42 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_O 31
# define KEY_P 35
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_M 46
# define KEY_N 45

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

typedef struct s_clr
{
	int	r;
	int	g;
	int	b;
}	t_clr;

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
void	mapinfo_free(t_mapinfo *map_info);

int		count_width(char *total);
int		count_height(char *total);
void	input_data(t_mapinfo *map_info);
void	control_map_info(t_mapinfo *map_info);

void	start_mlx(t_mapinfo *map_info);
void	init_image(t_mapinfo *map);

void	my_image_put_pixel(int x, int y, t_img *img, int color);
int		draw_line(t_mapinfo *map);
void	divide_gap(t_mapinfo *map);

int		check_input_w_h(t_spos *cur, t_spos *cur_n, int *w, int *h);
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

int		press_button(int keycode, void *map);
int		press_esc(t_mapinfo *map);
int		press_red_cross(int keycode, int x, int y, void *map);
void	press_right(t_mapinfo *map);
void	press_left(t_mapinfo *map);

void	press_up(t_mapinfo *map);
void	press_down(t_mapinfo *map);
void	press_o(t_mapinfo *map);
void	press_p(t_mapinfo *map);
void	zoom_in_out(int keycode, t_mapinfo *map);

void	press_translate(int keycode, t_mapinfo *map);
void	press_w(t_mapinfo *map);
void	press_s(t_mapinfo *map);
void	press_a(t_mapinfo *map);
void	press_d(t_mapinfo *map);

int		clr(t_spos *cur, t_spos *cur_n, t_spos *start);
int		calc_color(int color, int color_diff, double dist_ratio);
void	init_clr(t_clr *clr, t_spos *cur);

#endif