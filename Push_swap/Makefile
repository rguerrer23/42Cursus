NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj
SRC_FILES = check_args.c \
            main.c \
            rotate.c \
            sort.c \
            swap.c \
			utils.c 
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INC_DIR) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
