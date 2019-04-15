/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:34:32 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 15:57:02 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t step;

	step = 0;
	if (((unsigned char*)src) > ((unsigned char*)dst))
	{
		while (step < len)
		{
			((unsigned char*)dst)[step] = ((unsigned char*)src)[step];
			step++;
		}
		return (((unsigned char*)dst));
	}
	step = 1;
	while (step <= len)
	{
		(((unsigned char*)dst)[len - step] = ((unsigned char*)src)[len - step]);
		step++;
	}
	return (((unsigned char*)dst));
}
