# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicordie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 15:47:28 by nicordie          #+#    #+#              #
#    Updated: 2023/05/15 14:39:22 by nicordie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_toupper.c ft_tolower.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		  ft_memcmp.c ft_strnstr.c ft_atoi.c \
		  ft_split.c ft_itoa.c ft_striteri.c \
		  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		  get_next_line.c get_next_line_utils.c \
		  ft_printf.c ft_printf_type.c ft_printf_hex.c ft_printf_ptr.c

SOURCES_BNS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
			  ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
			  ft_lstnew.c ft_lstsize.c

INCLUDES = libft.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BNS = $(SOURCES_BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
		ar -rc $(NAME) $(OBJECTS)

bonus: $(OBJECTS_BNS) $(INCLUDES)
		ar -rc $(NAME) $(OBJECTS_BNS)

clean:
		rm -f $(OBJECTS)
		rm -f $(OBJECTS_BNS)

fclean: clean
		rm -f $(NAME)

re: fclean all
