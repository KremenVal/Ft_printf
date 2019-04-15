/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:37:05 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:04:36 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t step;
	size_t len_dst;
	size_t len_src;
	size_t i;

	step = 0;
	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	if (dstsize - 1 < len_dst)
		return (len_src + dstsize);
	while (dst[i] && i < dstsize)
		i++;
	while (src[step] && i + step < dstsize - 1)
	{
		dst[i + step] = src[step];
		step++;
	}
	dst[i + step] = '\0';
	return (len_dst + len_src);
}
