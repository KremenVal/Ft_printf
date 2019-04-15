/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:02:15 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 16:40:59 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t step;
	size_t i;

	step = 0;
	i = 0;
	while ((step < len) && src[step])
	{
		dst[step] = src[step];
		step++;
	}
	while (src[step] == '\0' && step + i < len)
	{
		dst[step + i] = '\0';
		i++;
	}
	return (dst);
}
