/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:58:14 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 13:59:49 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **cmd, char **env, char *file)
{
	int		fd2;

	close(fd[0]);
	fd2 = open(file, O_RDONLY, 0777);
	if (fd2 == -1)
		ft_error("zsh: no such file or directory: ", file);
	dup2(fd2, 0);
	close(fd2);
	dup2(fd[1], 1);
	if (execve(get_cmd_path(cmd[0], env), cmd, env) == -1)
	{
		ft_error("Command error", NULL);
		ft_free_array(cmd);
		exit(0);
	}
	ft_free_array(cmd);
}

void	parent_process(int *fd, char **cmd, char **env, char *file)
{
	int		fd2;

	close(fd[1]);
	fd2 = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd2 == -1)
		ft_error("File error", NULL);
	dup2(fd2, 1);
	close(fd2);
	dup2(fd[0], 0);
	close(fd[0]);
	if (execve(get_cmd_path(cmd[0], env), cmd, env) == -1)
	{
		ft_error("Command error", NULL);
		ft_free_array(cmd);
		exit(0);
	}
	ft_free_array(cmd);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	int		pid;
	char	**cmd1;
	char	**cmd2;

	if (ac != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2", NULL);
	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
	if (pipe(fd) == -1)
		ft_error("Pipe error", NULL);
	pid = fork();
	if (pid < 0)
		ft_error("Fork error", NULL);
	if (!pid)
		child_process(fd, cmd1, env, av[1]);
	else
		parent_process(fd, cmd2, env, av[4]);
	ft_free_array(cmd1);
	ft_free_array(cmd2);
	return (0);
}
