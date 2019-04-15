/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:23:17 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:23:27 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_num_base(unsigned long long num, int base, char **answer, char *str)
{
	unsigned long long int	copy_num;
	unsigned long long int	len;

	len = 0;
	copy_num = num;
	while (copy_num > 0)
	{
		copy_num /= base;
		len++;
	}
	if (!((*answer) = (char*)malloc(sizeof(char) * len)))
		return ;
	(*answer)[len--] = '\0';
	while (num > 0)
	{
		(*answer)[len--] = str[num % base];
		num /= base;
	}
}

char	*ft_itoa_base(unsigned long long int num, int base, char letter)
{
	char	*answer;
	char	*str_big_x;
	char	*str_x;

	answer = NULL;
	str_big_x = "0123456789ABCDEF";
	str_x = "0123456789abcdef";
	if (num == 0)
	{
		answer = (char*)malloc(sizeof(char) + 1);
		if (answer == 0)
			return (0);
		answer[0] = '0';
		answer[1] = '\0';
		return (answer);
	}
	if (base == 8 || base == 10 || letter == 'x')
		ft_num_base(num, base, &answer, str_x);
	else if (letter == 'X')
		ft_num_base(num, base, &answer, str_big_x);
	return (answer);
}
