/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:36:09 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/10 13:36:09 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec(char *av, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_path = get_cmd_path(av, env);
	cmd_args = ft_split(av, ' ');
	if (!cmd_path)
	{
		ft_free_array(cmd_args);
		ft_error("Error: command not found");
	}
	if(execve(cmd_path, cmd_args, env) == -1)
	{
		ft_free_array(cmd_args);
		ft_error("Error: execve failed");
	}
}

void	here_doc(char *limiter)
{
	int		fd[2];
	int		pid;
	char	*line;

	if (pipe(fd) == -1)
		ft_error("Pipe error");
	pid = fork();
	if (pid < 0)
		ft_error("Fork error");
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(0, &line) > 0)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				break ;
			ft_putstr_fd(line, fd[1]);
			ft_putstr_fd("\n", fd[1]);
			free(line);
		}
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

void	child_process(char *av, char **env)
{
	int		fd[2];
	int		pid;

	if (pipe(fd) == -1)
		ft_error("Pipe error");
	pid = fork();
	if (pid < 0)
		ft_error("Fork error");
	if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exec(av, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	
}

int main (int ac, char **av, char **env)
{
	int		narg;
	int		fdout;
	int		fdin;

	if(ac < 5)
		ft_error("Error: Not enough arguments");
	if(ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if(ac < 6)
			ft_error("Error: Not enough arguments");
		narg = 3;
		fdout = open(av[ac-1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		here_doc(av[2]);
	}
	else
	{
		narg = 2;
		fdin = open(av[1], O_RDONLY, 0777);
		fdout = open(av[ac-1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(fdin, 0);
	}
	while(narg < ac - 2)
		child_process(av[narg++], env);
	dup2(fdout, 1);
	exec(av[ac-2], env);
}
