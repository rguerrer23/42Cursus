NAME = megaphone
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = megaphone.cpp

OBJ = $(SOURCES:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re