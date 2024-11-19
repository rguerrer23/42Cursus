NAME = Harl
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = Harl.cpp \
		main.cpp \

HEADERS = Harl.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)