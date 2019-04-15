/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_other_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:26:05 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:26:06 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_printf_char_str(char *num, t_struct_d x, char *type)
{
	if (ft_strchr(type, 'c'))
	{
		if (x.minus == '-')
		{
			fill_buff(&num[0]);
			while (--x.width > 0)
				fill_buff(" ");
		}
		else
		{
			while (--x.width > 0)
				(x.zero == '0' ? fill_buff("0") : fill_buff(" "));
			fill_buff(&num[0]);
		}
	}
	else
	{
		if (x.minus == '-')
			printf_flag_minus_str(num, x);
		else
			printf_other_flags_str(num, x);
	}
}

void	start_printf_pointer_percent(char *num, t_struct_d x,
	char *fl, char *type)
{
	if (ft_strchr(type, 'p'))
	{
		if (x.minus == '-')
			printf_all_flags_unsigned_oct_hex(num, x, 17, fl);
		else
			printf_other_flags_pointer(num, x, fl);
	}
	else
		start_printf_percent(x);
}

void	start_printf_percent(t_struct_d x)
{
	int		step;

	step = 0;
	if (x.minus != '-')
	{
		if (x.zero == '0')
			while (++step < x.width)
				fill_buff("0");
		else
			while (++step < x.width)
				fill_buff(" ");
		fill_buff("%");
	}
	else
	{
		fill_buff("%");
		while (--x.width > 0)
			fill_buff(" ");
	}
}
