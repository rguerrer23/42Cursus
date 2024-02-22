NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

HEADER = -I ./includes

SOURCES = src/main.c \
			src/check_args.c \
			src/init.c \
			src/utils.c \
			src/threads.c \
			src/monitor.c \
			src/philo_routine.c \
			src/ft_atoi.c \
			src/ft_isdigit.c \
			src/ft_putnbr_fd.c \
			src/ft_putstr_fd.c \

OBJ = $(SOURCES:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

ALL: $(NAME)

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ > /dev/null

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(HEADER) $(OBJ) -o $(NAME) -lpthread > /dev/null
	@echo "$(GREEN)Compilation of $(NAME) done.$(NO_COLOR)"

clean:
	@echo "$(YELLOW)Cleaning objects...$(NO_COLOR)"
	@rm -f $(OBJ) > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(NO_COLOR)"
	@rm -f $(NAME) > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

re: fclean ALL

.PHONY: ALL clean fclean re