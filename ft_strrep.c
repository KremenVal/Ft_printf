/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:11:47 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 16:07:12 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrep(char *str, int f, int c)
{
	char	*answer;
	int		step;

	step = 0;
	answer = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (answer == 0)
		return (0);
	while (str[step])
	{
		if (str[step] == f)
			answer[step] = c;
		else
			answer[step] = str[step];
		step++;
	}
	answer[step] = '\0';
	return (answer);
}
