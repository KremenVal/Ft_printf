/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:14:45 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/26 16:46:03 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int step;
	int len_s1;

	step = 0;
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[step])
	{
		s1[len_s1] = s2[step];
		len_s1++;
		step++;
	}
	s1[len_s1] = '\0';
	return (s1);
}
