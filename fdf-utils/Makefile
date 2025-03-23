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

NAME = libft.a

SRC = ft_isascii.c\
	ft_strlcpy.c\
	ft_tolower.c\
	ft_isdigit.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_bzero.c\
    	ft_isprint.c\
      	ft_memset.c\
     	ft_strncmp.c\
	ft_isalnum.c\
	ft_memchr.c\
	ft_strchr.c\
	ft_strnstr.c\
	ft_isalpha.c\
     	ft_strlcat.c\
      	ft_strrchr.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strdup.c\
	ft_calloc.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putnbr_fd.c\
	ft_memcmp.c\
	ft_itoa.c\
	ft_atoi.c\
	ft_split.c

SRC_BONUS = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c
	
CC = gcc

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS) $(OBJ)
	ar rcs $(NAME) $(OBJ_BONUS) $(OBJ) 

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY = bonus clean all fclean re
