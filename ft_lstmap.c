/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:12:45 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:34:57 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *p;

	if (lst != NULL && f != NULL)
	{
		p = (t_list*)malloc(sizeof(t_list));
		if (p == NULL)
			return (NULL);
		p = (*f)(lst);
		if (lst->next)
		{
			p->next = ft_lstmap(lst->next, f);
			if (p->next == NULL)
				return (NULL);
		}
		else
			p->next = NULL;
		return (p);
	}
	return (NULL);
}
