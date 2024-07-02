/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:53:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/20 17:35:55 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

/* Esta funcion sale del minishell. */

void	ft_exit(t_shell *shell)
{
	// liberar memoria antes de salir
	exit(EXIT_SUCCESS);
}
