/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:26:24 by vkremen           #+#    #+#             */
/*   Updated: 2019/01/17 16:26:25 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_flag_minus_str(char *num, t_struct_d x)
{
	int		step;
	char	*str;

	step = -1;
	if (x.prec != -1)
	{
		while (++step < x.prec && step < (int)ft_strlen(num))
		{
			str = ft_strsub((char*)num + step, 0, 1);
			fill_buff(str);
			free(str);
		}
		step--;
		while (++step < x.width)
			fill_buff(" ");
	}
	else
	{
		fill_buff(num);
		step += (int)ft_strlen(num);
		while (++step < x.width)
			fill_buff(" ");
	}
}

void	printf_other_flags_str(char *num, t_struct_d x)
{
	int		step;
	char	*str;

	step = -1;
	if (x.prec > (int)ft_strlen(num) || x.prec < 1)
	{
		while (++step < x.width - (int)ft_strlen(num))
			(x.zero == '0' ? fill_buff("0") : fill_buff(" "));
		fill_buff(num);
	}
	else
	{
		while (++step < x.width - x.prec)
			(x.zero == '0' ? fill_buff("0") : fill_buff(" "));
		step = -1;
		while (++step < x.prec && step < (int)ft_strlen(num))
		{
			str = ft_strsub((char*)num + step, 0, 1);
			fill_buff(str);
			free(str);
		}
	}
}
