NAME = FragTrap
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		main.cpp \

HEADERS = ClapTrap.hpp \
		ScavTrap.hpp \
		FragTrap.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)