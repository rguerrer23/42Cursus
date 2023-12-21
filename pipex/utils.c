/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:00:47 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/21 11:38:12 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

char	*get_env_var(char *var, char **env)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (ft_strncmp(env[i], var, j) == 0)
		{
			value = ft_strdup(env[i] + j + 1);
			return (value);
		}
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	**path_dirs;
	char	*path;
	int		i;

	path_dirs = ft_split(get_env_var("PATH", env), ':');
	i = 0;
	while (path_dirs[i])
	{
		path = ft_strjoin(path_dirs[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	ft_error("Command not found");
	return (NULL);
}
