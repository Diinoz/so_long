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

SRC = src/create_map.c src/parsing.c src/path.c \
		src/so_long.c src/create_window.c src/clear.c

SRC_BONUS = bonus/create_map.c bonus/parsing.c bonus/path.c bonus/so_long.c \
			bonus/create_window.c bonus/clear.c bonus/animations.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C includes/libft_so_long
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) includes/libft_so_long/*.o $(MLXFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I. -Ilibft

clean:
	make -C includes/libft_so_long clean
	$(RM) $(OBJS)

fclean: clean
	make -C includes/libft_so_long fclean
	$(RM) $(NAME)

re: fclean all

bonus:
	make -C includes/libft_so_long
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_BONUS) includes/libft_so_long/*.o \
	$(MLXFLAGS)

.PHONY: all clean fclean re bonus
