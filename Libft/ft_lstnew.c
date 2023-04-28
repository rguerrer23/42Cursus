/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:04:32 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/28 12:04:32 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*x;

	x = malloc(sizeof(t_list));
	if (!x)
		return (NULL);
	x->content = content;
	x->next = NULL;
	return (x);
}
