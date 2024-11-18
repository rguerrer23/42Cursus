NAME = megaphone
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = megaphone.cpp

RM = rm -f

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)