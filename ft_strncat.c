/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:24:23 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 16:51:00 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t step;
	size_t len_s1;

	step = 0;
	len_s1 = ft_strlen(s1);
	while (step < n && s2[step] != '\0')
	{
		s1[len_s1] = s2[step];
		len_s1++;
		step++;
	}
	s1[len_s1] = '\0';
	return (s1);
}
