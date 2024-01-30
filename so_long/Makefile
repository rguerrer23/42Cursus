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
			src/move.c \

OBJ = $(SOURCES:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

ALL: libft libmlx $(NAME)

libft:
	@echo "$(YELLOW)Compiling libft...$(NO_COLOR)"
	@make -C $(LIBFT) > /dev/null
	@echo "$(GREEN)Compilation of libft done.$(NO_COLOR)"

libmlx:
	@echo "$(YELLOW)Compiling libmlx...$(NO_COLOR)"
	@make -C $(LIBMLX) > /dev/null
	@echo "$(GREEN)Compilation of libmlx done.$(NO_COLOR)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ > /dev/null

$(NAME): $(OBJ) $(LIBS)
	@echo "$(YELLOW)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(HEADER) $(LIBS) $(OBJ) -o $(NAME) $(LIBGL) > /dev/null
	@echo "$(GREEN)Compilation of $(NAME) done.$(NO_COLOR)"

clean:
	@echo "$(YELLOW)Cleaning objects...$(NO_COLOR)"
	@rm -f $(OBJ) > /dev/null
	@make clean -C $(LIBFT) > /dev/null
	@make clean -C $(LIBMLX) > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(NO_COLOR)"
	@rm -f $(NAME) > /dev/null
	@make fclean -C $(LIBFT) > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

re: fclean ALL

.PHONY: ALL clean fclean re libft libmlx