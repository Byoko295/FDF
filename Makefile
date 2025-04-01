# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 22:36:14 by mbenouis          #+#    #+#              #
#    Updated: 2024/12/18 12:22:36 by mbenouis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

SRC = fdf_files/parsing.c

CC = gcc

OBJ = $(SRC:.c=.o)

UTILS_DIR = utils

UTILS = $(UTILS_DIR)/libutils.a

MLX_DIR = minilibx-linux

MLX = $(MLX_DIR)/libmlx.a


CFLAGS = -g3 -Wall -Wextra -Werror -Lminilibx-linux -lmlx -lXext -lX11


all : $(MLX) $(UTILS) $(NAME) 


$(MLX) :
	$(MAKE) --silent -C $(MLX_DIR)

$(UTILS) :
	$(MAKE) --silent -C $(UTILS_DIR)

$(NAME) : $(OBJ) get_mlx $(UTILS) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(UTILS) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) --silent -C $(MLX_DIR) clean
fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)
	$(MAKE) --silent -C $(UTILS_DIR) fclean

re: fclean all

get_mlx:
	wget https://cdn.intra.42.fr/document/document/31602/minilibx-linux.tgz
	tar -xvf minilibx-linux.tgz
	rm -f minilibx-linux.tgz

.PHONY = get_mlx clean all fclean re 

