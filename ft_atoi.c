/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:04:36 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 17:25:38 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int res;
	int sign;
	int step;

	res = 0;
	sign = 1;
	step = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32 || *str == '0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str++ - '0';
		step++;
	}
	if (step <= 10)
		return (res * sign);
	if (sign == -1)
		return (0);
	return (-1);
}
