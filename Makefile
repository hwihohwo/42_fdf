# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 17:02:16 by seonghwc          #+#    #+#              #
#    Updated: 2023/03/07 18:59:25 by seonghwc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = fdf
CC						= cc
SRCS                    = ./srcs/main.c \
						  ./srcs/ft_strtol_16_fdf.c \
						  ./srcs/open_file.c \
						  ./srcs/map_error_check.c \
						  ./srcs/control_map_info.c \
						  ./srcs/exit_funcs.c \
						  ./srcs/mlx_hub.c \
						  ./srcs/draw_line.c \
						  ./srcs/bresenham.c \
						  ./srcs/isometric_projection.c \
						  ./srcs/rotate.c \
						  ./srcs/key_hook_1.c \
						  ./srcs/key_hook_2.c \
						  ./srcs/key_hook_3.c \
						  ./srcs/color.c
BNS_SRCS				= ./srcs_bns/main_bonus.c \
						  ./srcs_bns/ft_strtol_16_fdf_bonus.c \
						  ./srcs_bns/open_file_bonus.c \
						  ./srcs_bns/map_error_check_bonus.c \
						  ./srcs_bns/control_map_info_bonus.c \
						  ./srcs_bns/exit_funcs_bonus.c \
						  ./srcs_bns/mlx_hub_bonus.c \
						  ./srcs_bns/draw_line_bonus.c \
						  ./srcs_bns/bresenham_bonus.c \
						  ./srcs_bns/isometric_projection_bonus.c \
						  ./srcs_bns/rotate_bonus.c \
						  ./srcs_bns/key_hook_1_bonus.c \
						  ./srcs_bns/key_hook_2_bonus.c \
						  ./srcs_bns/key_hook_3_bonus.c \
						  ./srcs_bns/color_bonus.c
OBJS                    = $(SRCS:%.c=%.o)
BNS_OBJS				= $(BNS_SRCS:%.c=%.o)
COMP_OBJS				= $(OBJS)
FLAGS                   = -Wall -Wextra -Werror
MLX						= -L ./ -lmlx -framework OpenGL -framework AppKit
LIBFT					= -L ./libft/ -lft

ifdef FLAG_BONUS
	COMP_OBJS = $(BNS_OBJS)
endif

all :   $(NAME)

$(NAME)     :   $(COMP_OBJS)
	$(MAKE) -C libft/
	$(MAKE) -C mlx/
	$(CC) $(FLAGS) -o $(NAME) $(COMP_OBJS) -lm $(MLX) $(LIBFT) -I ./srcs/

bonus   :  
	make fclean FLAG_BONUS=1 all

clean   :
	rm -f $(OBJS)
	rm -f $(BNS_OBJS)
	$(MAKE) -C libft/ clean
	$(MAKE) -C mlx/ clean

fclean  :   clean
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean
	$(MAKE) -C mlx/ fclean

re  :   fclean all

.PHONY  :   all clean fclean re