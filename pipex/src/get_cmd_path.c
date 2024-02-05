/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:52 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/01 11:06:43 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(char *path_dir, char *cmd)
{
	char	*path;
	char	*exec_path;

	path = ft_strjoin(path_dir, "/");
	exec_path = ft_strjoin(path, cmd);
	free(path);
	return (exec_path);
}

char	*check_access(char **path_dirs, char *tmp)
{
	int		i;
	char	*exec_path;

	i = 0;
	while (path_dirs[i])
	{
		exec_path = join_path(path_dirs[i], tmp);
		if (access(exec_path, X_OK | F_OK) == 0)
		{
			ft_free_array(path_dirs);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	return (NULL);
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
	char	*tmp;
	char	*path_env;

	path_env = get_env_var("PATH", env);
	if (!path_env)
		path_env = ft_strdup ("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	path_dirs = ft_split(path_env, ':');
	free(path_env);
	tmp = ft_strdup(cmd);
	exec_path = check_access(path_dirs, tmp);
	if (!exec_path)
	{
		ft_free_array(path_dirs);
		ft_error("zsh: command not found: ", cmd);
		return (tmp);
	}
	free(tmp);
	return (exec_path);
}
