/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:58:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/16 11:55:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

int		main(int ac, char **av, char **env);
void	ft_error(char *str, char *arg);
char	*get_cmd_path(char *cmd, char **env);
void	ft_free_array(char **array);

#endif