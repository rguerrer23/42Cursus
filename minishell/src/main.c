/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/02 12:03:39 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	shell_init(t_shell *shell, char **envp)
{
	shell->envp = envp;
	shell->tokens = NULL;
	shell->ast = NULL;
	shell->exit_status = 0;
	shell->pid = 0;
	shell->fd_in = STDIN_FILENO;
	shell->fd_out = STDOUT_FILENO;
	shell->fd_err = STDERR_FILENO;
	return (EXIT_SUCCESS);
}

void	shell_prompt(t_shell *shell)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		exit_shell(shell, EXIT_FAILURE);
	ft_putstr_fd(SHELL_PROMPT, shell->fd_out);
	ft_putstr_fd(cwd, shell->fd_out);
	ft_putstr_fd("$ ", shell->fd_out);
	free(cwd);
}

void	shell_read(t_shell *shell)
{
	shell->line = readline(NULL);
	if (!shell->line)
		exit_shell(shell, EXIT_SUCCESS);
	if (ft_strlen(shell->line) > 0)
		add_history(shell->line);
}

void	shell_clean(t_shell *shell)
{
	if (shell->line)
		free(shell->line);
	if (shell->tokens)
		free_tokens(shell->tokens);
	if (shell->ast)
		free_ast(shell->ast);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	if (argc != 1 || argv[1])
	{
		ft_putstr_fd("minishell: invalid arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
 	while (1)
	{
		shell_init(&shell, envp);
		shell_prompt(&shell);
		shell_read(&shell);
		shell_lexer(&shell);
		shell_parser(&shell);
		shell_execute(&shell);
		shell_clean(&shell);
	} 
	return (0);
}