/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:48:15 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 17:16:54 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_slice(char *str, size_t start, size_t finish)
{
	char	*res;
	size_t	step;

	if (finish < start || ft_strlen(str) < finish || ft_strlen(str) < start)
		return (0);
	res = (char*)malloc(sizeof(char) * (finish - start) + 1);
	if (res == 0)
		return (0);
	step = 0;
	while (start < finish)
	{
		res[step] = str[start];
		step++;
		start++;
	}
	res[step] = '\0';
	return (res);
}
