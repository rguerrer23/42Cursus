/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:51:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/18 21:23:25 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Funcion "ft_printf" jmartos-.
# include "ft_printf.h"

// Funcion "get_next_line" jmartos-.
# include "get_next_line.h"

// Operar con caracteres.
# include <ctype.h>

// Manipular strings.
# include <string.h>

// Gestion de memoria para cadenas/arrays.
# include <stdlib.h>

// Para el "printf".
# include <stdio.h>

// Para el "write".
# include <unistd.h>

// Para el "size_t".
# include <stddef.h>

// INT_MIN y INT_MAX.
# include <limits.h>

// Estructura con contenido y puntero, para listas enlazadas.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**************************/
/* FUNCIONES OBLIGATORIAS */
/**************************/

int		ft_isalpha(int x);
int		ft_isdigit(int x);
int		ft_isalnum(int x);
int		ft_isascii(int x);
int		ft_isprint(int x);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

/*************************/
/* FUNCIONES ADICIONALES */
/*************************/

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*********/
/* BONUS */
/*********/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**********************************/
/* FUNCIONES Y ESTRUCTURAS NUEVAS */
/**********************************/

// Comprobamos que se ha introducido un array de caracteres numericos.
int		ft_isdigit_str(char *str);

// Cuenta las palabras de un string usando un delimitador.
int		ft_word_counter(char const *s, char c);

// Duplica con seguridad una matriz bidimensional (similar a ft_strdup).
char	**ft_matrixdup(char **matrix);

#endif