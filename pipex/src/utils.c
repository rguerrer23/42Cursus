/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:00:47 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/16 12:32:38 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, char *arg)
{
	ft_putstr_fd(str, 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
