/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:38:04 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/30 15:38:06 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_flags(char *res, t_struct_d *x)
{
	int step;

	step = 0;
	if (ft_strchr(res, '+'))
		x->plus = '+';
	if (ft_strchr(res, '-'))
		x->minus = '-';
	if (ft_strchr(res, ' '))
		x->space = ' ';
	if (ft_strchr(res, '#'))
		x->sh = '#';
	while (res[step])
	{
		if (res[step] == '0' && res[step + 1] != '.')
			x->zero = '0';
		else if (res[step] != '+' && res[step] != '-'
			&& res[step] != '#' && res[step] != ' '
			&& res[step] != '0')
			break ;
		step++;
	}
}

void	find_flag_width(char *res, t_struct_d *x)
{
	int		step;

	step = 0;
	while (res[step])
	{
		if ((res[step] >= '1' && res[step] <= '9') && x->width == -1)
			x->width = ft_atoi((char*)res + step);
		else if (res[step] == '.')
			break ;
		step++;
	}
}

void	find_flag_precision(char *res, t_struct_d *x)
{
	int		i;
	char	*str;

	i = 0;
	while (res[i])
	{
		if (res[i] == '.')
		{
			if (x->width == -1)
				x->width = 0;
			if (res[i + 1] == '-' || res[i + 1] == '+' || res[i + 1] == ' '
				|| res[i + 1] == '#')
			{
				x->width = -1;
				find_flag_width((char*)res + i + 1, x);
				x->prec = 0;
			}
			x->prec = ft_atoi((char*)res + i + 1);
			str = ft_itoa(x->prec);
			i += (int)ft_strlen(str) - 1;
			free(str);
		}
		i++;
	}
}
