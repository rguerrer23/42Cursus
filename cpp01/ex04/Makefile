NAME = replace
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = main.cpp

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)