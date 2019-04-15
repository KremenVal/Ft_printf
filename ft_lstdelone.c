/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:00:27 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/01 14:42:39 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	if (alst != NULL && del != NULL)
	{
		p = *alst;
		del(p->content, p->content_size);
		free(p);
		*alst = NULL;
	}
}
