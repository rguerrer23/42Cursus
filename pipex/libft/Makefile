NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs

SOURCES = ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strdup.c ft_strncmp.c ft_strlen.c ft_strchr.c ft_split2.c

OBJ = $(SOURCES:.c=.o)

RM = rm -f

.c.o:
	$(CC) -c $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re