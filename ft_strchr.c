/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:05:58 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 20:06:12 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int step;

	step = 0;
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (s[step])
	{
		if (s[step] == c)
			return ((char*)s + step);
		step++;
	}
	return (0);
}
