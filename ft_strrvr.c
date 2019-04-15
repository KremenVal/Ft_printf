/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrvr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:43:55 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 16:08:05 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrvr(char *str)
{
	char	*answer;
	int		len;
	int		step;

	len = ft_strlen(str) - 1;
	step = 0;
	answer = (char*)malloc(sizeof(char) * len + 1);
	if (answer == 0)
		return (0);
	while (len >= 0)
	{
		answer[step] = str[len];
		len--;
		step++;
	}
	answer[step] = '\0';
	return (answer);
}
