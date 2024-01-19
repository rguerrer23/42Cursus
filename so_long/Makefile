NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft
LIBMLX = ./MLX42/build

HEADER = -I ./includes/ -I ${LIBMLX}/include -I ${LIBFT}
LIBGL = -lglfw -L"/Users/rguerrer/.brew/opt/glfw/lib/"
LIBS = ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a

SOURCES = main.c \
			map.c \
			check_map.c \
			init_game.c \
			utils.c \
			images.c \
			key_hook.c \

OBJ = $(SOURCES:.c=.o)

ALL: libft libmlx $(NAME)

libft:
	@make -C $(LIBFT)

libmlx:
	@make -C $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(LIBS) $(OBJ) -o $(NAME) $(LIBGL)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean ALL

.PHONY: ALL clean fclean re libft libmlx