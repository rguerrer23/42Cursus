/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:24:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/05/02 12:24:27 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	shell_lexer(t_shell *shell)
{
	shell->tokens = ft_split(shell->line, ' ');
	if (!shell->tokens)
		exit_shell(shell, EXIT_FAILURE);
}