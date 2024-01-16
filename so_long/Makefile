NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX42 = 

LIBFT = libft/libft.a

SOURCES = main.c \
			init_game.c \
			init_images.c \
			run_game.c \
			end_game.c

OBJ = $(SOURCES:.c=.o)

ALL: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I minilibx-linux/ -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean ALL

.PHONY: ALL clean fclean re	