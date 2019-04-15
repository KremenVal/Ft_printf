/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:37:48 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:37:16 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int step;

	if (s != NULL && f != NULL)
	{
		step = 0;
		while (s[step])
		{
			f(step, &s[step]);
			step++;
		}
	}
}
