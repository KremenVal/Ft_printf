/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:06:56 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:22:24 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t step;

	step = 0;
	while (step < n)
	{
		((unsigned char*)dst)[step] = ((unsigned char*)src)[step];
		if (((unsigned char*)src)[step] == ((unsigned char)c))
			return (dst + step + 1);
		step++;
	}
	return (0);
}
