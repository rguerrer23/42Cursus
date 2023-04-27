# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 16:32:21 by rguerrer          #+#    #+#              #
#    Updated: 2023/04/27 20:18:40 by rguerrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi.c ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c \
		ft_strlen.c ft_substr.c ft_isalnum.c ft_isprint.c ft_memmove.c \
		ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalpha.c ft_memchr.c \
		ft_memset.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
		ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
		ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		
OBJS		= $(FILES:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(FILES) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all