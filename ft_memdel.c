/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:09:14 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/28 19:24:41 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_memdel(void **ap)
{
	if (*ap != NULL && ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
