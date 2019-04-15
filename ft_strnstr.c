/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:18:23 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 17:50:43 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t step;
	size_t occur;

	step = 0;
	if (needle[step] == '\0')
		return ((char*)haystack);
	while (haystack[step] && step < len)
	{
		occur = 0;
		if (haystack[step] == needle[occur])
		{
			while (haystack[step] == needle[occur] && step < len)
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
