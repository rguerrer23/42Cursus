NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_isdigit.c \

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