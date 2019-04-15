/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int_and_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:25:26 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:25:27 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_all_flags(char *num, t_struct_d x)
{
	int		step;
	char	*str;

	step = 0;
	str = (num[0] == '-' ? ((char*)num + 1) : num);
	(num[0] == '-' ? fill_buff("-") : fill_buff("+"));
	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) > x.prec)
	{
		fill_buff(str);
		return ;
	}
	if (x.prec >= (int)ft_strlen(num))
		while (++step < x.prec - (int)ft_strlen(num))
			fill_buff("0");
	fill_buff(str);
	while (++step < x.width - (int)ft_strlen(str))
		fill_buff(" ");
}

void	printf_flag_plus(char *num, t_struct_d x)
{
	int		step;
	char	*str;

	str = (num[0] == '-' ? ((char*)num + 1) : num);
	step = 0;
	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) > x.prec)
	{
		(num[0] == '-' ? fill_buff("-") : fill_buff("+"));
		fill_buff(str);
		return ;
	}
	if ((int)ft_strlen(str) < x.prec)
		while (++step < x.width - x.prec)
			fill_buff(" ");
	else if ((int)ft_strlen(str) > x.prec && x.zero != '0')
		while (++step < x.width - (int)ft_strlen(str))
			fill_buff(" ");
	(num[0] == '-' ? fill_buff("-") : fill_buff("+"));
	if (x.prec == -1 && x.zero == '0')
		while (++step < x.width - (int)ft_strlen(str))
			fill_buff("0");
	else if (x.prec >= (int)ft_strlen(num))
		while (++step < x.prec - (int)ft_strlen(str))
			fill_buff("0");
	fill_buff(str);
}

void	printf_flag_minus(char *num, t_struct_d x)
{
	int		step;
	char	*str;

	step = -1;
	str = (num[0] == '-' ? ((char*)num + 1) : num);
	if (num[0] == '-')
		fill_buff("-");
	else if (num[0] != '-' && x.space == ' ')
		fill_buff(" ");
	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) > x.prec)
	{
		fill_buff(str);
		return ;
	}
	if (x.prec >= (int)ft_strlen(num))
	{
		while (++step < x.prec - (int)ft_strlen(str))
			fill_buff("0");
		step--;
	}
	fill_buff(str);
	while (++step < x.width - (int)ft_strlen(num))
		fill_buff(" ");
}

void	printf_other_flags_part_1(char *num, t_struct_d x)
{
	int		step;
	char	*str;

	step = -1;
	str = (num[0] == '-' ? ((char*)num + 1) : num);
	if (num[0] != '-' && x.space == ' ')
		fill_buff(" ");
	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) > x.prec)
	{
		if (num[0] == '0' && x.prec == 0)
			;
		else
			fill_buff(num);
		return ;
	}
	printf_other_flags_part_2(num, x);
	if (x.prec >= (int)ft_strlen(num) && x.prec != 0)
		while (++step < x.prec - (int)ft_strlen(num) + SIGN(num[0]))
			fill_buff("0");
	(num[0] == '0' && x.prec == 0 ? fill_buff(" ") : fill_buff(str));
}
