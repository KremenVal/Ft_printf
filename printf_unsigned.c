/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:27:04 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:27:04 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_all_flags_unsigned_oct_hex(char *num, t_struct_d x,
	int base, char *fl)
{
	int step;

	(x.sh == '#' && base == 8 ? fill_buff("0") : 0);
	(x.sh == '#' && base == 16 ? fill_buff(ft_strjoin("0", fl)) : 0);
	(base == 17 ? fill_buff(ft_strjoin("0", fl)) : 0);
	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) > x.prec)
	{
		fill_buff(num);
		return ;
	}
	step = (x.sh == '#' && base == 8 ? 0 : -1);
	if (x.prec >= (int)ft_strlen(num))
	{
		while (++step < x.prec - (int)ft_strlen(num))
			fill_buff("0");
		step--;
	}
	fill_buff(num);
	step += (int)ft_strlen(num) + ((x.sh == '#' && base == 16) || base == 17
		? 2 : 0);
	while (++step < x.width)
		fill_buff(" ");
}

void	printf_flag_plus_unsigned(char *num, t_struct_d x)
{
	int step;

	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) > x.prec)
	{
		fill_buff(num);
		return ;
	}
	step = -1;
	if ((int)ft_strlen(num) > x.prec)
		while (++step < x.width - (int)ft_strlen(num))
			fill_buff(" ");
	else
		while (++step < x.width - x.prec)
			fill_buff(" ");
	if (x.prec == -1 && x.zero == '0')
		while (++step < x.width - (int)ft_strlen(num))
			fill_buff("0");
	else if (x.prec >= (int)ft_strlen(num))
		while (++step < x.prec - (int)ft_strlen(num))
			fill_buff("0");
	fill_buff(num);
}

void	printf_other_flags_unsigned(char *num, t_struct_d x)
{
	int step;

	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) > x.prec)
	{
		(num[0] == '0' && x.prec == 0 ? 0 : fill_buff(num));
		return ;
	}
	step = -1;
	if ((int)ft_strlen(num) > x.prec)
		while (++step < x.width - (int)ft_strlen(num))
			(x.prec == -1 && x.zero == '0' ? fill_buff("0") : fill_buff(" "));
	else
		while (++step < x.width - x.prec)
			fill_buff(" ");
	step = -1;
	while (++step < x.prec - (int)ft_strlen(num))
		fill_buff("0");
	(num[0] == '0' && x.prec == 0 ? fill_buff(" ") : fill_buff(num));
}
