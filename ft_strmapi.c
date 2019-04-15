/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:55:21 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:36:40 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			answer[step] = f(step, s[step]);
			step++;
		}
		answer[step] = '\0';
		return (answer);
	}
	return (0);
}
