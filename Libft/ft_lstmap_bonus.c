/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:09:17 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/29 12:09:17 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lista;
	t_list	*listadef;

	if (!lst)
		return (NULL);
	lista = ft_lstnew((*f)(lst->content));
	if (!lista)
	{
		ft_lstclear(&lista, del);
		return (NULL);
	}
	listadef = lista;
	lst = lst->next;
	while (lst != NULL)
	{
		lista->next = ft_lstnew((*f)(lst->content));
		lista = lista->next;
		if (!lista)
		{
			ft_lstclear(&lista, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (listadef);
}
