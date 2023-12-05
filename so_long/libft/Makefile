NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_bzero.c \
			ft_calloc.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			get_next_line.c \
			get_next_line_utils.c 

OBJ = $(SOURCES:.c=.o)

ALL: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean ALL

.PHONY: ALL clean fclean re