/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 22:24:05 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/28 22:31:11 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *s)
{
	int step;

	if (s != NULL)
	{
		step = 0;
		while (s[step])
		{
			write(1, &s[step], 1);
			step++;
		}
	}
}
