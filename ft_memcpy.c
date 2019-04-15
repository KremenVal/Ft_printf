/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:57:55 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:17:23 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t step;

	step = 0;
	while (step < n)
	{
		((unsigned char*)dst)[step] = ((unsigned char*)src)[step];
		step++;
	}
	return (((unsigned char*)dst));
}
