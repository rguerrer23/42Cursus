NAME = account_test
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = tests.cpp \
		Account.cpp \

HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)