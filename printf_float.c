/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:24:58 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:25:00 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_flag_plus_float(char *num, t_struct_d x)
{
	int		step;
	int		len;
	char	*str;

	str = (num[0] == '-' ? ((char*)num + 1) : num);
	len = len_num_befor_point(str);
	if (x.prec == -1)
		x.prec = ft_strlen(ft_strchr(num, '.') + 1);
	step = 0;
	if (len < x.width && x.zero == '0')
	{
		(num[0] == '-' ? fill_buff("-") : fill_buff("+"));
		while (++step < x.width - len)
			fill_buff("0");
	}
	else
	{
		while (++step < x.width - len)
			fill_buff(" ");
		(num[0] == '-' ? fill_buff("-") : fill_buff("+"));
	}
	fill_buff(str);
	if (x.prec < 1 && x.sh == '#')
		fill_buff(".");
}

void	printf_flag_minus_float(char *num, t_struct_d x)
{
	int		step;
	int		len;
	char	*str;

	str = (num[0] == '-' ? ((char*)num + 1) : num);
	step = -1;
	len = len_num_befor_point(num) + (x.plus == '+' ? 1 : 0);
	if (x.prec == -1)
		x.prec = ft_strlen(ft_strchr(num, '.') + 1);
	if (x.prec == 0 && x.plus != '+')
		len--;
	if (num[0] == '-' || x.plus == '+')
		(num[0] == '-' ? fill_buff("-") : fill_buff("+"));
	else if (num[0] != '-' && x.space == ' ')
		fill_buff(" ");
	(num[0] == '-' ? fill_buff((char*)num + 1) : fill_buff(num));
	if (x.prec < 1 && x.sh == '#')
		fill_buff(".");
	while (--x.width > x.prec + len)
		fill_buff(" ");
}

void	printf_other_flags_float(char *num, t_struct_d x)
{
	int		step;
	int		len;

	step = -1;
	len = len_num_befor_point(num);
	if (x.prec == -1)
		x.prec = ft_strlen(ft_strchr(num, '.') + 1);
	if (num[0] != '-' && x.space == ' ')
		fill_buff(" ");
	if (len < x.width && x.zero == '0')
	{
		(num[0] == '-' ? fill_buff("-") : 0);
		while (++step < x.width - len)
			fill_buff("0");
	}
	else if (len < x.width)
	{
		while (++step < x.width - len)
			fill_buff(" ");
		(num[0] == '-' ? fill_buff("-") : 0);
	}
	else
		(num[0] == '-' ? fill_buff("-") : 0);
	(num[0] == '-' ? fill_buff((char*)num + 1) : fill_buff(num));
	(x.prec < 1 && x.sh == '#' ? fill_buff(".") : 0);
}
