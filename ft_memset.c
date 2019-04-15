/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:55:11 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:06:59 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t step;

	step = 0;
	while (step < len)
	{
		((unsigned char*)b)[step] = (unsigned char)c;
		step++;
	}
	return (((unsigned char*)b));
}
