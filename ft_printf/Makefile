NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rc

SOURCES = ft_printf.c ft_print_char.c ft_print_punt.c ft_print_str.c ft_print_int.c ft_print_uint.c ft_print_hex.c ft_print_hexcap.c

OBJ = $(SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus