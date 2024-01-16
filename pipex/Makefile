NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

SOURCES = src/pipex.c \
			src/utils.c \
			src/get_cmd_path.c \
			libft/libft.a \

OBJ = $(SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

libft/libft.a:
	make all -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
