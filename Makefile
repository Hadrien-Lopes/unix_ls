NAME=ft_ls
CC=gcc
CFLAGS+=-Wall -Wextra -Werror
LIB=-L ./libft -lft
SRC=./sources/main.c \
	./sources/sort.c \
	./sources/list_option.c \
	./sources/useful.c \
	./sources/option.c \
	./sources/var_size.c \
	./sources/disp_option.c \
	./sources/argv_sort_useful.c \
	./sources/argv_sort_folder.c \
	./sources/argv_sort_files.c \
	./sources/ls_display_useful.c \
	./sources/ls_start_useful.c \
	./sources/sort_files.c \
	./sources/recursive_option.c \
	./sources/recursive_option_useful.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	(cd ./libft && make)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	(cd ./libft && make clean)
	rm -rf $(OBJ)

fclean: clean
	(cd ./libft && make fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re relib reall
