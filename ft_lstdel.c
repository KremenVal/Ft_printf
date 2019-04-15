/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:14:11 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/01 14:40:36 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;

	if (alst != NULL && del != NULL)
	{
		p = *alst;
		while (p != NULL)
		{
			del(p->content, p->content_size);
			free(p);
			p = p->next;
		}
		*alst = NULL;
	}
}
