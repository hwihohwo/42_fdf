# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 17:02:16 by seonghwc          #+#    #+#              #
#    Updated: 2023/02/25 21:14:06 by marvin           ###   ########.fr        #
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
						  ./srcs/bresenhum.c \
						  ./srcs/isometric_projection.c \
						  ./srcs/rotate.c \
						  ./srcs/key_hook_1.c \
						  ./srcs/key_hook_2.c \
						  ./srcs/key_hook_3.c
OBJS                    = $(SRCS:%.c=%.o)
FLAGS                   = -Wall -Wextra -Werror
MLX						= -L ./ -lmlx -framework OpenGL -framework AppKit
LIBFT					= -L ./libft/ -lft

all :   $(NAME)

$(NAME)     :   $(OBJS)
	$(MAKE) -C libft/
	$(MAKE) -C mlx/
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -lm $(MLX) $(LIBFT) -I ./srcs/

clean   :
	rm -f $(OBJS)
	$(MAKE) -C libft/ clean
	$(MAKE) -C mlx/ clean

fclean  :   clean
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean
	$(MAKE) -C mlx/ fclean

re  :   fclean all

.PHONY  :   all clean fclean re