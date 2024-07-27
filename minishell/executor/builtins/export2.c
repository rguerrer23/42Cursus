/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:41:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/27 16:23:11 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env_error2(int bad_env, char *env, int i)
{
	if (bad_env == -1)
	{
		ft_putstr_fd("export: not valid in this context: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
		{
			ft_putchar_fd(env[i], STDERR_FILENO);
			i++;
		}
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (bad_env == -2)
	{
		ft_putstr_fd("export: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
			i++;
		i++;
		ft_putchar_fd(env[i], STDERR_FILENO);
		ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
	}
}

void	ft_env_error(int bad_env, char *env)
{
	int	i;

	i = 0;
	if (bad_env == 0)
	{
		ft_putstr_fd("export: not an identifier: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
		{
			ft_putchar_fd(env[i], STDERR_FILENO);
			i++;
		}
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (bad_env == -3)
	{
		if (env[1] != '\0')
			bad_env = -2;
		else
		{
			ft_putstr_fd("export: not valid in this context", STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
		}
	}
	ft_env_error2(bad_env, env, i);
}

int	is_bad_env(char *env)
{
	int	i;

	i = 0;
	if (ft_isdigit(env[i]))
		return (0);
	if (env[i] == '=')
		return (-3);
	while (env[i])
	{
		if (env[i] == '=')
		{
			if (env[i + 1] == '=' && env[i + 2] != '\0')
				return (-2);
		}
		i++;
	}
	i = 0;
	while (env[i] && env[i] != '=')
	{
		if (!ft_isalnum(env[i]) && env[i] != '_')
			return (-1);
		i++;
	}
	return (1);
}

t_var	*create_new_entry(char *value_var, char *name_var)
{
	t_var	*new_entry;

	new_entry = (t_var *)malloc(sizeof(t_var));
	if (!new_entry)
		return (NULL);
	new_entry->key = ft_strdup(name_var);
	if (value_var)
		new_entry->value = ft_strdup(value_var);
	else
		new_entry->value = NULL;
	return (new_entry);
}

void	ft_new_env(char *name_var, char *value_var, t_shell *shell)
{
	int		i;
	t_var	**new_env;
	t_var	*new_entry;

	i = 0;
	while (shell->env_list[i])
		i++;
	new_env = (t_var **)malloc(sizeof(t_var *) * (i + 2));
	if (!new_env)
		return ;
	i = 0;
	while (shell->env_list[i])
	{
		new_env[i] = shell->env_list[i];
		i++;
	}
	new_entry = create_new_entry(value_var, name_var);
	new_env[i] = new_entry;
	new_env[i + 1] = NULL;
	free(shell->env_list);
	shell->env_list = new_env;
}
