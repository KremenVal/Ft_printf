/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:36:08 by vkremen           #+#    #+#             */
/*   Updated: 2018/12/04 20:36:10 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_struct_int(char *num, char *type, t_struct_d x)
{
	int		base;
	char	*value;

	if (ft_strchr(type, 'x') || ft_strchr(type, 'X'))
		value = ft_strchr(type, 'X') ? "X" : "x";
	else
		value = "a";
	base = (ft_strchr(type, 'x') || ft_strchr(type, 'X') ? 16 : 8);
	if (ft_strchr(type, 'd') || ft_strchr(type, 'i'))
		start_printf_int(num, x);
	else if (ft_strchr(type, 'u'))
		start_printf_unsigned(num, x);
	else if (ft_strchr(type, 'o') || ft_strchr(type, 'x')
		|| ft_strchr(type, 'X'))
		start_printf_oct_hex(num, x, base, value);
	else if (ft_strchr(type, 'f'))
		start_printf_float(num, x);
	else if (ft_strchr(type, 'c') || ft_strchr(type, 's'))
		start_printf_char_str(num, x, type);
	else if (ft_strchr(type, 'p') || ft_strchr(type, '%'))
		start_printf_pointer_percent(num, x, "x", type);
	free(num);
}

void	check_type(char *type, char *res, va_list ap)
{
	t_struct_d	x;

	x.width = -1;
	x.prec = -1;
	find_flags(res, &x);
	find_flag_width(res, &x);
	find_flag_precision(res, &x);
	find_struct_int(return_int(ap, type, x), type, x);
}

void	find_type(char *res, va_list ap)
{
	char	*type;
	int		i;

	i = -1;
	type = NULL;
	while (res[++i])
	{
		if ((res[i] >= 'a' && res[i] <= 'z') && type == NULL)
		{
			type = ft_strdup((char*)res + i);
			break ;
		}
		else if ((res[i] >= 'A' && res[i] <= 'X') && type == NULL)
		{
			type = ft_strdup((char*)res + i);
			break ;
		}
		else if (res[i] == '%' && type == NULL)
		{
			type = ft_strdup((char*)res + i);
			break ;
		}
	}
	check_type(type, res, ap);
	free(type);
}

int		ft_printf(char *format, ...)
{
	va_list		ap;

	g_step = 0;
	g_null = 0;
	ft_bzero(g_buff, 10000);
	va_start(ap, format);
	ft_printf_parcing(format, ap);
	va_end(ap);
	write(1, &g_buff, (int)ft_strlen(g_buff));
	return (g_step + g_null);
}
