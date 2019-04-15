/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:03:43 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/28 22:11:19 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	step;
	char	*res;

	if (s != NULL)
	{
		step = 0;
		len_s = ft_strlen(s);
		if (start > len_s || len_s - start < len)
			return (0);
		res = (char*)malloc(sizeof(char) * len + 1);
		if (res == 0)
			return (0);
		while (step < len)
		{
			res[step] = s[start];
			step++;
			start++;
		}
		res[step] = '\0';
		return (res);
	}
	return (0);
}
