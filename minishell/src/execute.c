/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:55:35 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/08 10:55:35 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	shell_execute(t_shell *shell)
{
	shell->pid = fork();
	if (shell->pid < 0)
		exit_shell(shell, EXIT_FAILURE);
	if (shell->pid == 0)
	{
		if (shell->fd_in != STDIN_FILENO)
		{
			if (dup2(shell->fd_in, STDIN_FILENO) < 0)
				exit_shell(shell, EXIT_FAILURE);
			close(shell->fd_in);
		}
		if (shell->fd_out != STDOUT_FILENO)
		{
			if (dup2(shell->fd_out, STDOUT_FILENO) < 0)
				exit_shell(shell, EXIT_FAILURE);
			close(shell->fd_out);
		}
		if (shell->fd_err != STDERR_FILENO)
		{
			if (dup2(shell->fd_err, STDERR_FILENO) < 0)
				exit_shell(shell, EXIT_FAILURE);
			close(shell->fd_err);
		}
		execve(shell->tokens[0], shell->tokens, shell->envp);
		exit_shell(shell, EXIT_FAILURE);
	}
	waitpid(shell->pid, &shell->exit_status, 0);
}