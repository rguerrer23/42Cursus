NAME = Zombie
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = Zombie.cpp \
		main.cpp \
		randomChump.cpp \
		newZombie.cpp

HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)