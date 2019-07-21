# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 16:37:06 by ahaloua           #+#    #+#              #
#    Updated: 2019/07/21 16:51:11 by ahaloua          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -c -Wall -Wextra -Werror
FILES = fillit.c \
		solve.c \
		map.c \
		check.c \
		main.c \

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

