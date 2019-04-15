/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:44:41 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 16:36:55 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	size_t	step;
	char	*answer;

	answer = (char*)malloc(sizeof(char) * size + 1);
	if (answer == 0)
		return (0);
	step = 0;
	while (step <= size)
	{
		answer[step] = '\0';
		step++;
	}
	return (answer);
}
