/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/02 12:51:36 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define SHELL_NAME "minishell"
# define SHELL_PROMPT "minishell$ "

typedef struct s_shell
{
	char		**envp;
	char		*line;
	char		**tokens;
	char		**ast;
	int			exit_status;
	pid_t		pid;
	int			fd_in;
	int			fd_out;
	int			fd_err;
}				t_shell;

int		main(int argc, char **argv, char **envp);
void	exit_shell(t_shell *shell, int status);

#endif