NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft

HEADER = -I ./includes/ -I ${LIBFT}
LIBS = ${LIBFT}/libft.a

SOURCES = src/main.c \
			src/check_args.c \
			src/init.c \
			src/utils.c \
			src/threads.c \
			src/monitor.c \
			src/philo_routine.c \

OBJ = $(SOURCES:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

ALL: libft $(NAME)

libft:
	@echo "$(YELLOW)Compiling libft...$(NO_COLOR)"
	@make -C $(LIBFT) > /dev/null
	@echo "$(GREEN)Compilation of libft done.$(NO_COLOR)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ > /dev/null

$(NAME): $(OBJ) $(LIBS)
	@echo "$(YELLOW)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(HEADER) $(LIBS) $(OBJ) -o $(NAME) -lpthread -Llibft -lft > /dev/null
	@echo "$(GREEN)Compilation of $(NAME) done.$(NO_COLOR)"

clean:
	@echo "$(YELLOW)Cleaning objects...$(NO_COLOR)"
	@rm -f $(OBJ) > /dev/null
	@make clean -C $(LIBFT) > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(NO_COLOR)"
	@rm -f $(NAME) > /dev/null
	@make fclean -C $(LIBFT) > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

re: fclean ALL

.PHONY: ALL clean fclean re libft