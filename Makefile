# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicordie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 15:07:07 by nicordie          #+#    #+#              #
#    Updated: 2024/01/09 15:47:09 by nicordie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework AppKit -framework OpenGL
RM = rm -f
SRC = create_map.c parsing.c path.c so_long.c create_window.c clear.c
OBJS = $(SRC:.c=.o)
INCLUDES = -Iincludes -Imlx
GNL = ./includes/get_next_line/get_next_line.a
PRINTF = ./includes/printf/libftprintf.a
LIBFT = ./includes/libft/libft.a

all: $(NAME)
$(NAME): start
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLXFLAGS) \
	$(INCLUDES) $(GNL) $(PRINTF) $(LIBFT)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I.

start :
	make -C includes/printf all
	make -C includes/get_next_line all
	make -C includes/libft all

clean:
	$(RM) $(OBJS)
	make -C includes/printf all
	make -C includes/get_next_line all
	make -C includes/libft all

fclean: clean
	$(RM) $(NAME)
	make -C includes/printf fclean
	make -C includes/get_next_line fclean
	make -C includes/libft all

re: fclean all

.PHONY: all clean fclean re
