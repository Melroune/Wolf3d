# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/26 16:38:20 by akerkeb           #+#    #+#              #
#    Updated: 2015/06/27 11:14:31 by akerkeb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

SRC=  srcs/main.c srcs/get_next_line.c srcs/wolf.c srcs/ray.c srcs/move.c srcs/key_hook.c

OBJ= $(SRC:.c=.o)

CC= gcc

CFLAGS= -Wextra -Wall -Werror

RM= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	mv *.o ./srcs
	make -C libft/ fclean
	make -C libft/
	make -C minilibx_macos
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./minilibx_macos/libmlx.a -I ./includes -I ./minilibx_macos/ -framework OpenGL -framework AppKit -L libft/ -lft

$(OBJ):
	$(CC) $(CFLAGS) -I ./includes -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
