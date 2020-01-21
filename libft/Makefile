# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 10:29:13 by hmoulher          #+#    #+#              #
#    Updated: 2018/11/29 11:55:24 by hmoulher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c\
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_reverse.c \
		ft_sort_integer_table.c \
		ft_strcat_malloc.c \
		ft_strndup.c \
		ft_localtime.c \
		get_next_line.c \
		./ft_printf/csp_specifier.c \
		./ft_printf/dioux_specifier.c \
		./ft_printf/diu_arg_detect.c \
		./ft_printf/f_specifier.c \
		./ft_printf/ft_ftoa.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_strjoin_free.c \
		./ft_printf/ft_strndup.c \
		./ft_printf/ft_unitoa.c \
		./ft_printf/moinsspluss.c \
		./ft_printf/ol.c \
		./ft_printf/ox_arg_detect.c \
		./ft_printf/signs.c \
		./ft_printf/silly_detect.c \
		./ft_printf/silly_detect_2.c \
		./ft_printf/struct_tools.c \
		./ft_printf/tools.c \
		./ft_printf/widthower.c
CC = gcc -Wall -Wextra -Werror
CFLAGS = -I .libft.h
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
