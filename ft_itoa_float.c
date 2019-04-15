/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:23:54 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:24:00 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	change_answer(char *answer, int x, int buff, int prec)
{
	while (--x > 0)
	{
		if (answer[x] >= '5' && buff == 1)
		{
			if (answer[x] >= '5' && answer[x] <= '8')
				answer[x] += buff;
			else if (answer[x] == '9' && prec == 1)
				answer[x] = '0';
			else if (answer[x] == '9' && answer[x - 1] != '.')
				answer[x] = '0';
		}
		else if (answer[x] < '5' && answer[x] != '.')
		{
			answer[x] += buff;
			buff = 0;
		}
		else if (answer[x] == '.')
		{
			(prec == 0 ? (answer[x - 1] += buff) : 0);
			break ;
		}
	}
}

char	*return_answer(int lenbp, char **answer, int prec)
{
	int		x;
	int		buff;
	char	*res;

	x = lenbp + prec;
	if ((*answer)[x + 1] >= '5' && (*answer)[x + 1] <= '9' && (*answer)[x])
		buff = 1;
	else
		buff = 0;
	x++;
	change_answer((*answer), x, buff, prec);
	res = ft_strsub((*answer), 0, lenbp + 1 + prec - (prec == 0 ? 1 : 0));
	free((*answer));
	return (res);
}

char	*fill_answer(long double n, int lenbp, int lenap, int sign)
{
	char	*answer;
	int		step;

	step = 0;
	answer = (char*)malloc(sizeof(char) * (lenbp + lenap + 2));
	if (sign == 1)
		answer[step++] = '-';
	if (lenbp == 0)
		answer[step++] = '0';
	while (step < lenbp)
	{
		n *= 10;
		answer[step++] = (int)n + '0';
		n -= (int)n;
	}
	answer[step++] = '.';
	while (step < lenbp + lenap + 2)
	{
		n *= 10;
		answer[step++] = (int)n + '0';
		n -= (int)n;
	}
	answer[step] = '\0';
	return (answer);
}

char	*ft_itoa_float(long double n, int prec)
{
	int		lenbp;
	int		sign;
	int		x;
	char	*answer;

	lenbp = 0;
	sign = (n < 0 ? 1 : 0);
	n *= (n < 0 ? -1 : 1);
	while (n > 1.0)
	{
		n = n / 10;
		lenbp++;
	}
	lenbp += (sign == 1 ? 1 : 0);
	x = (prec > -1 ? prec : 6) + (lenbp == 0 ? 1 : 0);
	answer = fill_answer(n, lenbp, (prec > 6 ? prec : 6), sign);
	return (return_answer(lenbp, &answer, x));
}
