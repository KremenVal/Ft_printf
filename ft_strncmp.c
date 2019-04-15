/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstrncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:50:44 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 17:50:19 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t step;

	if (n == 0)
		return (0);
	step = 0;
	while ((((unsigned char*)s1)[step] == ((unsigned char*)s2)[step]) &&
			((unsigned char*)s1)[step] && (step + 1 < n))
		step++;
	return (((unsigned char*)s1)[step] - ((unsigned char*)s2)[step]);
}
