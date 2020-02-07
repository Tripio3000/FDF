# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseabass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 17:55:39 by cseabass          #+#    #+#              #
#    Updated: 2020/01/31 17:55:42 by cseabass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = fdf.c get_next_line.c paint.c readfile1.c paint_2.c paint_3.c fdf_2.c paint_4.c fdf_3.c fdf_4.c
LIB = libft/libft.a
NAME = fdf
OBJ = $(patsubst %.c,%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft re
	@gcc -Wall -Wextra -Werror -L libft -lft $(FILES) -I libft -I fdf.h -o $(NAME) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
%.o: %.c
	@gcc -Wall -Werror -Wextra -I fdf.h $< -c -o $@

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re