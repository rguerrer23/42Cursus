/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:34:35 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/10 13:34:35 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
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
	char	*exec_path;
	char	*path;
	int		i;
	char	*tmp;

	path_dirs = ft_split(get_env_var("PATH", env), ':');
	tmp = ft_strdup(cmd);
	i = 0;
	while (path_dirs[i])
	{
		path = ft_strjoin(path_dirs[i], "/");
		exec_path = ft_strjoin(path, tmp);
		free(path);
		if (access(exec_path, X_OK | F_OK) == 0)
		{
			free(tmp);
			ft_free_array(path_dirs);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	free(tmp);
	ft_free_array(path_dirs);
	ft_error("Command not found");
	return (cmd);
}

int	get_next_line(int fd, char **line)
{
	char	*buffer;
	char	*tmp;
	int		ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!*line)
			*line = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(*line, buffer);
			free(*line);
			*line = tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ret);
}