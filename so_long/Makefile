NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBFT = ./libft
LIBMLX = ./MLX42

HEADER = -I ./include -I ${LIBMLX}/include -I ${LIBFT}
LIBGL = -lglfw -L"/Users/rguerrer/.brew/opt/glfw/lib/"
LIBS = ${LIBMLX}/build/libmlx42.a ${LIBFT}/libft.a

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
			src/draw_map.c \

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
	@echo "$(YELLOW)Compiling MLX42...$(NO_COLOR)"
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -C $(LIBMLX)/build -j4 > /dev/null 2>&1
	@echo "$(GREEN)Compilation of MLX42 done.$(NO_COLOR)"

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
	@rm -rf $(LIBMLX)/build > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(NO_COLOR)"
	@rm -f $(NAME) > /dev/null
	@make fclean -C $(LIBFT) > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

re: clean ALL

.PHONY: ALL clean fclean re libft libmlx