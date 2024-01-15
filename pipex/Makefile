NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

SOURCES = src/pipex.c \
			src/utils.c \
			libft/libft.a \

SOURCES_BONUS = src_bonus/pipex_bonus.c \
				src_bonus/utils_bonus.c \
				libft/libft.a \

OBJ = $(SOURCES:.c=.o)
OBJ_BONUS = $(SOURCES_BONUS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

libft/libft.a:
	make all -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

bonus : fclean libft/libft.a $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) libft/libft.a -o $(NAME)

.PHONY: all clean fclean re bonus
