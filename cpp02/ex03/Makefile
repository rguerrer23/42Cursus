NAME = fixed
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = Fixed.cpp \
		main.cpp \
		Point.cpp \
		bsp.cpp \

HEADERS = Fixed.hpp \
		Point.hpp \
		bsp.hpp \

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)