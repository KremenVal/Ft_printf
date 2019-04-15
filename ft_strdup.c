/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:06:15 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/27 13:43:03 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	int		step;
	char	*copy;

	len_s1 = ft_strlen(s1);
	copy = (char*)malloc(sizeof(char) * len_s1 + 1);
	step = 0;
	if (copy)
	{
		while (step < len_s1)
		{
			copy[step] = s1[step];
			step++;
		}
		copy[step] = '\0';
		return (copy);
	}
	return (0);
}
