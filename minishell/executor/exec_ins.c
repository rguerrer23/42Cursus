/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/02 17:03:58 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion ejecuta un comando de sistema. */

void	get_pid(t_shell *shell)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		shell->pid = 0;
	else if (pid < 0)
		shell->pid = -1;
	else
		shell->pid = pid;
}

void	execute_ins(t_cmd *cmd, t_shell *shell)
{
	int	status;

	status = 0;
	get_pid(shell);
	if (shell->pid == 0)
	{
		if (cmd->infile != 0)
		{
			dup2(cmd->infile, 0);
			close(cmd->infile);
		}
		if (cmd->outfile != 1)
		{
			dup2(cmd->outfile, 1);
			close(cmd->outfile);
		}
		status = execve(cmd->cmd_path, cmd->full_cmd, shell->env);
	}
	else if (shell->pid < 0)
	{
		ft_putstr_fd("minishell: fork failed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(shell->pid, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
}
