/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:39:41 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/27 14:29:44 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset_env(char **name_var, t_shell *shell, int x)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (shell->env_list[i] != NULL)
	{
		len = ft_strlen(name_var[x]);
		if (!ft_strncmp(shell->env_list[i]->key, name_var[x], len)
			&& shell->env_list[i]->key[len] == '\0')
		{
			free(shell->env_list[i]->key);
			free(shell->env_list[i]->value);
			free(shell->env_list[i]);
			j = i;
			while (shell->env_list[j] != NULL)
			{
				shell->env_list[j] = shell->env_list[j + 1];
				j++;
			}
			shell->env_list[j] = NULL;
			i--;
		}
		i++;
	}
}

void	ft_unset(char **name_var, t_shell *shell)
{
	int	x;

	x = 0;
	while (name_var[x] != NULL)
	{
		ft_unset_env(name_var, shell, x);
		x++;
	}
}
