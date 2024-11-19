NAME = fixed
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = Fixed.cpp \
		main.cpp \

HEADERS = Fixed.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)