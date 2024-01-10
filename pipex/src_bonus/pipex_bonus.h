/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:35:07 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/10 13:35:07 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 500

int		main(int ac, char **av, char **env);
void	ft_error(char *str);
void	ft_free_array(char **array);
char	*get_cmd_path(char *cmd, char **env);
int		get_next_line(int fd, char **line);

#endif