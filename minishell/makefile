NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

SOURCES = src/main.c \
		  src/parser.c \
		  src/execute.c \
		  src/utils.c \
		  src/lexer.c \

LIBS = libft/libft.a

OBJ = $(SOURCES:.c=.o)

RM = rm -f

GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@echo "$(YELLOW)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(CFLAGS)  $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME) -lreadline > /dev/null
	@echo "$(GREEN)Compilation of $(NAME) done.$(NO_COLOR)"

libft/libft.a:
	@echo "$(YELLOW)Compiling libft...$(NO_COLOR)"
	@make -s all -C libft > /dev/null
	@echo "$(GREEN)Compilation of libft done.$(NO_COLOR)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ > /dev/null

clean:
	@echo "$(YELLOW)Cleaning objects...$(NO_COLOR)"
	@$(RM) $(OBJ) > /dev/null
	@make clean -C libft > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(NO_COLOR)"
	@$(RM) $(NAME) > /dev/null
	@make fclean -C libft > /dev/null
	@echo "$(GREEN)Cleaning done.$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re