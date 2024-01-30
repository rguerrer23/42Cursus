NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft
LIBMLX = ./MLX42/build

HEADER = -I ./includes/ -I ${LIBMLX}/include -I ${LIBFT}
LIBGL = -lglfw -L"/Users/rguerrer/.brew/opt/glfw/lib/"
LIBS = ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a

SOURCES = src/main.c \
			src/map.c \
			src/check_map.c \
			src/check_way.c \
			src/check_objects.c \
			src/init_game.c \
			src/utils.c \
			src/images.c \
			src/key_hook.c \
			src/collects.c \

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