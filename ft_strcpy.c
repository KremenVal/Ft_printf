/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:39:18 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 16:39:13 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int step;

	step = 0;
	while (src[step])
	{
		dst[step] = src[step];
		step++;
	}
	dst[step] = '\0';
	return (dst);
}
