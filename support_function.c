/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:28:18 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:28:19 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_other_flags_part_2(char *num, t_struct_d x)
{
	int		step;

	step = -1 + (x.space == ' ' ? 1 : 0);
	if ((int)ft_strlen(num) > x.prec && x.zero == '0')
	{
		(num[0] == '-' ? fill_buff("-") : 0);
		if (x.prec < 0)
			while (++step < x.width - (int)ft_strlen(num))
				fill_buff("0");
		else
			while (++step < x.width - (int)ft_strlen(num))
				fill_buff(" ");
		return ;
	}
	else if ((int)ft_strlen(num) > x.prec)
		while (++step < x.width - (int)ft_strlen(num))
			fill_buff(" ");
	else
		while (++step < x.width - x.prec - SIGN(num[0]))
			fill_buff(" ");
	(num[0] == '-' ? fill_buff("-") : 0);
}

void	printf_other_flags_pointer(char *num, t_struct_d x, char *fl)
{
	int step;

	step = (x.prec == 0 ? 0 : 1);
	if ((int)ft_strlen(num) > x.width && (int)ft_strlen(num) >= x.prec)
	{
		fill_buff(ft_strjoin("0", fl));
		if (num[0] == '0' && x.prec == 0)
			;
		else
			fill_buff(num);
		return ;
	}
	if ((int)ft_strlen(num) > x.prec)
		while (++step < x.width - (int)ft_strlen(num))
			fill_buff(" ");
	else
		while (++step < x.width - x.prec)
			fill_buff(" ");
	fill_buff(ft_strjoin("0", fl));
	step = -1;
	if (x.prec > (int)ft_strlen(num))
		while (++step < x.prec - (num[0] != '0' ? (int)ft_strlen(num) : 0))
			fill_buff("0");
	if (x.prec == -1 || num[0] != '0')
		fill_buff(num);
}
