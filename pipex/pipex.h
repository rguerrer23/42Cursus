/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:58:32 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/20 17:47:42 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>

int		main(int ac, char **av, char **env);
void	ft_error(char *str);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*get_cmd_path(char *cmd, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_free_array(char **array);

#endif