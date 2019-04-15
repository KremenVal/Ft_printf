/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:18:36 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 20:46:05 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	int last_occ;
	int step;

	last_occ = -1;
	step = 0;
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (s[step])
	{
		if (s[step] == c)
			last_occ = step;
		step++;
	}
	if (last_occ != -1)
		return ((char*)s + last_occ);
	else
		return (0);
}
