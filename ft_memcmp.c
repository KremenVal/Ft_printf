/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:16:44 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 16:12:52 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t step;

	step = 0;
	while (step < n)
	{
		if (((unsigned char*)s1)[step] != ((unsigned char*)s2)[step])
			return (((unsigned char*)s1)[step] - ((unsigned char*)s2)[step]);
		step++;
	}
	return (0);
}
