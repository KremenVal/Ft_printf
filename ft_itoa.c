/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:37:40 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/29 12:13:37 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_itoa_num(long long int num, char **answer)
{
	long long int			sign;
	unsigned long long int	copy_num;
	long long int			len;

	sign = (num < 0 ? 1 : 0);
	copy_num = (num < 0 ? num * -1 : num);
	len = 0 + sign;
	while (copy_num > 0)
	{
		copy_num /= 10;
		len++;
	}
	if (!((*answer) = (char*)malloc(sizeof(char) * len)))
		return ;
	(*answer)[len--] = '\0';
	copy_num = (num < 0 ? num * -1 : num);
	while (copy_num > 0)
	{
		(*answer)[len--] = (copy_num % 10) + '0';
		copy_num /= 10;
	}
	if (sign == 1)
		(*answer)[len] = '-';
}

char			*ft_itoa(long long int num)
{
	char	*answer;

	if (num == 0)
	{
		answer = (char*)malloc(sizeof(char) + 1);
		if (answer == 0)
			return (0);
		answer[0] = '0';
		answer[1] = '\0';
		return (answer);
	}
	ft_itoa_num(num, &answer);
	return (answer);
}
