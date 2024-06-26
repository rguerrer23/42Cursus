/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/02 17:02:39 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int g_mutex = 0;


int	main(int ac, char **av, char **envp)
{
	t_shell	shell;
	t_cmd	cmd;

	(void)av;
	if (ac > 1)
	{
		ft_putstr_fd(RED"minishell: invalid arguments\n"NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	shell.env = envp;
	shell.line = NULL;
	char *full_cmd[] = {"ls", NULL};
	cmd.full_cmd = full_cmd;
	cmd.cmd_path = NULL;
	execute(&shell, &cmd);
	return (0);
}