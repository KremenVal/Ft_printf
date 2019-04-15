/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:16:38 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:37:00 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		step;
	char	*answer;

	if (s != NULL && f != NULL)
	{
		step = 0;
		answer = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (answer == 0)
			return (0);
		while (s[step])
		{
			answer[step] = f(s[step]);
			step++;
		}
		answer[step] = '\0';
		return (answer);
	}
	return (0);
}
