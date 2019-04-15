/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:39:27 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 17:15:35 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t step;

	if (s1 != NULL && s2 != NULL)
	{
		step = 0;
		while (step < n)
		{
			if (s1[step] != s2[step])
				return (0);
			step++;
		}
		return (1);
	}
	return (0);
}
