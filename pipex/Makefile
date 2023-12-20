NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

SOURCES = pipex.c \
			utils.c \
			libft/ft_split.c \
			libft/ft_putstr_fd.c \
			libft/ft_strjoin.c \
			libft/ft_strdup.c \
			libft/ft_strncmp.c \
			libft/ft_strlen.c \

INCLUDE = pipex.h

OBJ = $(SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
