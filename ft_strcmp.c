/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:41:57 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/27 13:46:39 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int step;

	step = 0;
	while ((((unsigned char*)s1)[step] == ((unsigned char*)s2)[step]) &&
		((unsigned char*)s1)[step])
		step++;
	return (((unsigned char*)s1)[step] - ((unsigned char*)s2)[step]);
}
