/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:20:18 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/02 13:20:18 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	exit_shell(t_shell *shell, int status)
{
	if (shell->line)
		free(shell->line);
	if (shell->tokens)
		free_tokens(shell->tokens);
	if (shell->ast)
		free_ast(shell->ast);
	exit(status);
}

