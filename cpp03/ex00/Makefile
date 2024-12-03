NAME = ClapTrap
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = ClapTrap.cpp \
		main.cpp \

HEADERS = ClapTrap.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)