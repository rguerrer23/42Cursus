NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

SOURCES = src/pipex.c \
			src/utils.c \
			libft/libft.a \

SOURCES_BONUS = src_bonus/pipex_bonus.c \
				src_bonus/utils_bonus.c \
				libft/libft.a \

RM = rm -f

$(NAME):
	make all -C libft
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

clean:
	$(RM) $(OBJ)
	make clean -C libft

re: fclean all

bonus : clean
	make all -C libft
	$(CC) $(CFLAGS) $(SOURCES_BONUS) -o $(NAME)

.PHONY: all clean fclean re bonus
