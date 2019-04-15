/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:59:20 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/28 20:18:32 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strclr(char *s)
{
	int step;

	if (s != NULL)
	{
		step = -1;
		while (s[++step])
			s[step] = '\0';
	}
}