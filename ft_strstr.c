/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:34:22 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 20:49:21 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int step;
	int occur;

	step = 0;
	if (needle[step] == '\0')
		return ((char*)haystack);
	while (haystack[step])
	{
		occur = 0;
		if (haystack[step] == needle[occur])
		{
			while (haystack[step] == needle[occur])
			{
				step++;
				occur++;
				if (needle[occur] == '\0')
					return ((char*)haystack + step - occur);
			}
			step -= occur;
		}
		step++;
	}
	return (0);
}
