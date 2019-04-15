/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:29:57 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 19:32:07 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int step;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	step = 0;
	while (s1[step] || s2[step])
	{
		if (s1[step] != s2[step])
			return (0);
		step++;
	}
	if (s1[step] != s2[step])
		return (0);
	return (1);
}
