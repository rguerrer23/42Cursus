/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:24:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/02 12:24:27 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char *ft_strspn(const char *s, const char *accept)
{
	int	i;

	i = 0;
	while (s[i] && ft_strchr(accept, s[i]))
		i++;
	return ((char *)&s[i]);
}

char *ft_strpbrk(const char *s, const char *accept)
{
	while (*s)
	{
		if (ft_strchr(accept, *s))
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char *ft_strtok(char *str, const char *delim)
{
	static char	*last = NULL;
	char		*token;
	char		*end;

	if (!str)
		str = last;
	if (!str)
		return (NULL);
	str = ft_strspn(str, delim);
	if (*str == '\0')
	{
		last = NULL;
		return (NULL);
	}
	token = str;
	end = ft_strpbrk(token, delim);
	if (end)
	{
		*end = '\0';
		last = end + 1;
	}
	else
		last = NULL;
	return (token);
}

char	**ft_tokenize(char *line)
{
	char	**tokens;
	char	*token;
	int		i;

	tokens = ft_calloc(ft_strlen(line) + 1, sizeof(char *));
	if (!tokens)
		return (NULL);
	i = 0;
	while (*line)
	{
		token = ft_strtok(line, " \t\n");
		if (token)
		{
			tokens[i] = token;
			i++;
		}
		line = NULL;
	}
	return (tokens);
}

void	shell_lexer(t_shell *shell)
{
	char	*tmpline;

	tmpline = shell->line;
	shell->tokens = ft_tokenize(tmpline);
	free(tmpline);
	shell->line = NULL;
	if (!shell->tokens)
		exit_shell(shell, EXIT_FAILURE);
}
