/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_diouxf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:24:39 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:24:40 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_printf_int(char *num, t_struct_d x)
{
	if (x.plus == '+' && x.minus == '-')
		printf_all_flags(num, x);
	else if (x.plus == '+')
		printf_flag_plus(num, x);
	else if (x.minus == '-')
		printf_flag_minus(num, x);
	else
		printf_other_flags_part_1(num, x);
}

void	start_printf_unsigned(char *num, t_struct_d x)
{
	if ((x.plus == '+' && x.minus == '-') || x.minus == '-')
		printf_all_flags_unsigned_oct_hex(num, x, 10, "a");
	else if (x.plus == '+')
		printf_flag_plus_unsigned(num, x);
	else
		printf_other_flags_unsigned(num, x);
}

void	start_printf_oct_hex(char *num, t_struct_d x, int base, char *fl)
{
	if (x.minus == '-')
		printf_all_flags_unsigned_oct_hex(num, x, base, fl);
	else if (x.sh != '#')
		pritf_flag_zero_oct_hex(num, x);
	else if (ft_strchr(fl, 'x') || ft_strchr(fl, 'X'))
		printf_other_flags_hex_part_1(num, x, fl);
	else
		printf_other_flags_oct(num, x);
}

void	start_printf_float(char *num, t_struct_d x)
{
	if (x.plus == '+' && x.minus != '-')
		printf_flag_plus_float(num, x);
	else if (x.minus == '-')
		printf_flag_minus_float(num, x);
	else
		printf_other_flags_float(num, x);
}
