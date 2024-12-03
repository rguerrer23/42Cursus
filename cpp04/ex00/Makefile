NAME = Animal
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		main.cpp

HEADERS = Animal.hpp \
		Cat.hpp \
		Dog.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)