NAME = violence
CC = g++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \
		main.cpp \

HEADERS = HumanA.hpp \
		HumanB.hpp \
		Weapon.hpp

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME) 

clean:
	rm -f $(NAME)