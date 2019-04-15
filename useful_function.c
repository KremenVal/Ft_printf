/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:28:31 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:28:32 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_len_type(char *format, int start)
{
	int len;

	len = 0;
	while (format[start + len] != 'd' && format[start + len] != 'i'
		&& format[start + len] != 'o' && format[start + len] != 'u'
		&& format[start + len] != 'x' && format[start + len] != 'X'
		&& format[start + len] != 'f' && format[start + len] != 'c'
		&& format[start + len] != 's' && format[start + len] != 'p'
		&& format[start + len] != '%' && format[start + len])
		len++;
	return (len);
}

int		len_num_befor_point(char *num)
{
	int len;

	len = 0;
	while (num[len] != '.' && num[len])
		len++;
	return (len);
}

void	fill_buff(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		g_buff[g_step++] = str[i++];
}

void	ft_printf_parcing(char *format, va_list ap)
{
	int		i;
	char	*res;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			res = ft_strsub(format, i + 1, find_len_type(format, i + 1) + 1);
			if (res == NULL)
				return ;
			find_type(res, ap);
			i += (int)ft_strlen(res);
			free(res);
		}
		else if (format[i] != '%')
		{
			res = ft_strsub((char*)format + i, 0, 1);
			fill_buff(res);
			free(res);
		}
		i++;
	}
}
