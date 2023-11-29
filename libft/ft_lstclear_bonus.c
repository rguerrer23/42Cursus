/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:49:08 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/29 11:49:08 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*x;
	t_list	*next;

	x = *lst;
	*lst = NULL;
	while (x != NULL)
	{
		next = x->next;
		del(x->content);
		free(x);
		x = next;
	}
}
