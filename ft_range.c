/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:15:14 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 16:02:22 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_range(int min, int max)
{
	int *result;
	int step;

	step = 0;
	if (min > max)
		return (0);
	result = (int*)malloc(sizeof(int) * (max - min));
	if (result == 0)
		return (0);
	while (min <= max)
	{
		result[step] = min;
		min++;
		step++;
	}
	return (result);
}
