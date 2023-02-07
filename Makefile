# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 17:02:16 by seonghwc          #+#    #+#              #
#    Updated: 2023/02/08 04:47:59 by seonghwc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = fdf
CC						= cc
SRCS                    = main.c \
						  ft_strtol_16_fdf.c \
						  input.c
OBJS                    = $(SRCS:%.c=%.o)
FLAGS                   = -Wall -Wextra -Werror
MLX						= -L ./ -lmlx -framework OpenGL -framework AppKit
LIBFT					= -L ./libft/ -lft

all :   $(NAME)

$(NAME)     :   $(OBJS)
	$(MAKE) -C libft/
	$(MAKE) -C mlx/
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -lm $(MLX) $(LIBFT) -I .

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