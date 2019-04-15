/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:00:36 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/29 11:08:07 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int step;

	if (s != NULL)
	{
		step = 0;
		while (s[step])
		{
			write(fd, &s[step], 1);
			step++;
		}
	}
}
