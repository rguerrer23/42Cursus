/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/02 16:55:15 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft/includes/libft.h"	// libft
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>				// señales (server/client)
# include <stdio.h> 				// redline
# include <readline/readline.h>		// redline
# include <readline/history.h>		// redline

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define STDIN_FILENO 0 // entrada estandar de informacion (por la terminal)
# define STDOUT_FILENO 1 // salida estandar de informacion (en la terminal)
# define STDERR_FILENO 2 // error en la salida estandar (en la terminal)

# define SHELL_NAME "minishell"
# define SHELL_PROMPT "minishell$ "

# define NC		"\033[0m"
# define RED	"\033[31;1m"

/*
	En t_shell;
		
		- *cmds		= puntero a la estructura de comandos.
		- *line		= linea de comandos leida por el shell.
		- **env		= matriz de punteros a las variables de entorno del shell.
		- pid		= id del proceso actual de la consola.
	
	En t_cmd;
		
		- **full_cmd= matriz de punteros a los comandos de la linea de comandos.
		- *cmd_path	= ruta del primer comandos encontrado en el input.
		- inline	= (STDIN 0) file descriptor a leer para ejecutar un comando.
		- outline	= (STDOUT 1)file descriptor a escribir para ejecutar un comando.
*/

typedef struct s_shell
{
	t_list	*cmds;
	char	*line;
	char	**env;
	pid_t		pid;
}				t_shell;

typedef struct s_cmd
{
	char	**full_cmd;
	char	*cmd_path;
	int		infile;
	int		outfile;
}				t_cmd;


int		main(int ac, char **av, char **envp);
int		ft_cd(char *path);
int		ft_echo(char **args);
void	ft_env(t_shell *shell);
void	ft_exit(t_shell *shell);
void	ft_export(char *name_var, char *value_var, t_shell *shell);
int		ft_pwd(void);
int		ft_unset(char *name_var, t_shell *shell);
void	execute(t_shell *shell, t_cmd *cmd);
void	execute_builtin(t_cmd *cmd, t_shell *shell);
void	execute_ins(t_cmd *cmd, t_shell *shell);
int		is_builtin(char *cmd);
int	ft_strcmp(const char *s1, const char *s2);
char	*get_cmd_path(char *cmd, t_shell *shell);
void	ft_error(char *str, char *arg);
void	ft_free_array(char **array);


#endif