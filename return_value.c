/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:27:16 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:27:17 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*return_int(va_list ap, char *type, t_struct_d x)
{
	char	*num;

	if (ft_strcmp(type, "d") == 0 || ft_strcmp(type, "i") == 0)
		num = ft_itoa(va_arg(ap, int));
	else if (ft_strcmp(type, "ld") == 0 || ft_strcmp(type, "li") == 0)
		num = ft_itoa(va_arg(ap, long int));
	else if (ft_strcmp(type, "hd") == 0 || ft_strcmp(type, "hi") == 0)
		num = ft_itoa((short int)va_arg(ap, int));
	else if (ft_strcmp(type, "lld") == 0 || ft_strcmp(type, "lli") == 0)
		num = ft_itoa(va_arg(ap, long long int));
	else if (ft_strcmp(type, "hhd") == 0 || ft_strcmp(type, "hhi") == 0)
		num = ft_itoa((signed char)va_arg(ap, int));
	else if ((ft_strchr(type, 'd') || ft_strchr(type, 'i'))
		&& ft_strchr(type, 'h') && !ft_strchr(type, 'l'))
		num = ft_itoa((signed char)va_arg(ap, int));
	else if ((ft_strchr(type, 'd') || ft_strchr(type, 'i'))
		&& ft_strchr(type, 'l'))
		num = ft_itoa(va_arg(ap, long int));
	else
		num = return_unsigned(ap, type, x);
	return (num);
}

char	*return_unsigned(va_list ap, char *type, t_struct_d x)
{
	char	*num;

	if (ft_strcmp(type, "u") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned int), 10, 'a');
	else if (ft_strcmp(type, "lu") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned long int), 10, 'a');
	else if (ft_strcmp(type, "hu") == 0)
		num = ft_itoa_base((unsigned short int)va_arg(ap, int), 10, 'a');
	else if (ft_strcmp(type, "llu") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned long long int), 10, 'a');
	else if (ft_strcmp(type, "hhu") == 0)
		num = ft_itoa_base((unsigned char)va_arg(ap, int), 10, 'a');
	else if (ft_strchr(type, 'u') && ft_strchr(type, 'h')
		&& !ft_strchr(type, 'l'))
		num = ft_itoa_base((unsigned char)va_arg(ap, int), 10, 'a');
	else if (ft_strchr(type, 'u') && ft_strchr(type, 'l'))
		num = ft_itoa_base(va_arg(ap, unsigned long int), 10, 'a');
	else
		num = return_oct(ap, type, x);
	return (num);
}

char	*return_oct(va_list ap, char *type, t_struct_d x)
{
	char	*num;

	if (ft_strcmp(type, "o") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned int), 8, 'a');
	else if (ft_strcmp(type, "lo") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned long int), 8, 'a');
	else if (ft_strcmp(type, "ho") == 0)
		num = ft_itoa_base((unsigned short int)va_arg(ap, int), 8, 'a');
	else if (ft_strcmp(type, "llo") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned long long int), 8, 'a');
	else if (ft_strcmp(type, "hho") == 0)
		num = ft_itoa_base((unsigned char)va_arg(ap, int), 8, 'a');
	else if (ft_strchr(type, 'o') && ft_strchr(type, 'h')
		&& !ft_strchr(type, 'l'))
		num = ft_itoa_base((unsigned char)va_arg(ap, int), 8, 'a');
	else if (ft_strchr(type, 'o') && ft_strchr(type, 'l'))
		num = ft_itoa_base(va_arg(ap, unsigned long int), 8, 'a');
	else
		num = return_hex(ap, type, x);
	return (num);
}

char	*return_hex(va_list ap, char *type, t_struct_d x)
{
	char	*num;
	char	letter;

	letter = (ft_strchr(type, 'x') || ft_strchr(type, 'p') ? 'x' : 'X');
	if (ft_strcmp(type, "x") == 0 || ft_strcmp(type, "X") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned int), 16, letter);
	else if (ft_strcmp(type, "lx") == 0 || ft_strcmp(type, "lX") == 0
		|| ft_strcmp(type, "p") == 0 || ft_strcmp(type, "lp") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned long int), 16, letter);
	else if (ft_strcmp(type, "hx") == 0 || ft_strcmp(type, "hX") == 0)
		num = ft_itoa_base((unsigned short int)va_arg(ap, int), 16, letter);
	else if (ft_strcmp(type, "llx") == 0 || ft_strcmp(type, "llX") == 0)
		num = ft_itoa_base(va_arg(ap, unsigned long long int), 16, letter);
	else if (ft_strcmp(type, "hhx") == 0 || ft_strcmp(type, "hhX") == 0)
		num = ft_itoa_base((unsigned char)va_arg(ap, int), 16, letter);
	else if ((ft_strchr(type, 'x') || ft_strchr(type, 'X'))
		&& ft_strchr(type, 'h') && !ft_strchr(type, 'l'))
		num = ft_itoa_base((unsigned char)va_arg(ap, int), 16, letter);
	else if ((ft_strchr(type, 'x') || ft_strchr(type, 'X'))
		&& ft_strchr(type, 'l'))
		num = ft_itoa_base(va_arg(ap, unsigned long int), 16, letter);
	else
		num = return_other(ap, type, x);
	return (num);
}

char	*return_other(va_list ap, char *type, t_struct_d x)
{
	char	*num;
	char	*str;

	if (ft_strchr(type, 'f') && !(ft_strchr(type, 'L')))
		num = ft_itoa_float(va_arg(ap, double), x.prec);
	else if (ft_strchr(type, 'f') && (ft_strchr(type, 'L')))
		num = ft_itoa_float(va_arg(ap, long double), x.prec);
	else if (ft_strchr(type, 'c'))
	{
		num = (char*)malloc(sizeof(char) * 2);
		num[0] = va_arg(ap, int);
		(num[0] == 0 ? g_null++ : 0);
		num[1] = '\0';
	}
	else if (ft_strchr(type, 's'))
	{
		str = va_arg(ap, char*);
		printf("%s\n", str);
		if (str == NULL)
			num = ft_strdup("(null)");
		else
			num = ft_strdup(str);
	}
	else
		num = ft_memalloc(2);
	return (num);
}
