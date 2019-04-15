/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:44:49 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 16:07:59 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t step;

	step = 0;
	while (step < n)
	{
		if (((unsigned char*)s)[step] == (unsigned char)c)
			return (((unsigned char*)s) + step);
		step++;
	}
	return (0);
}
