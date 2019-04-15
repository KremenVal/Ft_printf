/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:28:28 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 17:19:00 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	char	*area;
	size_t	step;

	step = 0;
	area = (char*)malloc(sizeof(char) * size);
	if (area == 0)
		return (0);
	while (step < size)
	{
		area[step] = 0;
		step++;
	}
	return (area);
}
