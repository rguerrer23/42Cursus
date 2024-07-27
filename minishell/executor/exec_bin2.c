/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:05:48 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/27 18:22:01 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	handle_redirections(t_shell *shell)
{
	if (shell->fdin > 2)
	{
		dup2(shell->fdin, STDIN_FILENO);
		close(shell->fdin);
	}
	if (shell->fdout > 2)
	{
		dup2(shell->fdout, STDOUT_FILENO);
		close(shell->fdout);
	}
}

char	**ft_env_to_array(t_var **env_list)
{
	int		i;
	char	**env_array;
	char	*tmp;

	i = 0;
	while (env_list[i] != NULL)
		i++;
	env_array = (char **)malloc(sizeof(char *) * (i + 1));
	if (env_array == NULL)
		return (NULL);
	i = 0;
	while (env_list[i] != NULL)
	{
		tmp = ft_strjoin(env_list[i]->key, "=");
		env_array[i] = ft_strjoin(tmp, env_list[i]->value);
		free(tmp);
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

static void	execute_child_process(char *path, char **exc, t_shell *shell)
{
	char	**env_array;

	handle_redirections(shell);
	env_array = ft_env_to_array(shell->env_list);
	if (ft_strchr(path, '/') != NULL)
		execve(path, exc, env_array);
	shell->g_status = error_msg(path);
	exit(shell->g_status);
}

void	exc(char *path, t_cmd **cmd, t_shell *shell, int i)
{
	pid_t	pid;
	int		status;
	char	**exc;

	exc = ft_undo(cmd, i);
	pid = fork();
	if (pid == 0)
		execute_child_process(path, exc, shell);
	waitpid(pid, &status, 0);
	shell->g_status = status;
	if (shell->fdin > 2)
		close(shell->fdin);
	if (shell->fdout > 2)
		close(shell->fdout);
	if (shell->g_status == 32512 || shell->g_status == 32256)
		shell->g_status /= 256;
}
