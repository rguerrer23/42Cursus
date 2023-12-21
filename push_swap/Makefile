NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = check_args.c \
			check_dupli.c \
			main.c \
			move.c \
			push.c \
			rotate.c \
			rotate2.c \
			sort.c \
			swap.c \
			target_cost.c \
			utils.c \
			ft_split.c

INCLUDE = push_swap.h

OBJ = $(SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
