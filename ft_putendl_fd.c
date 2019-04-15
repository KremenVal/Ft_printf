/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:09:50 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/01 14:11:06 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putendl_fd(char const *s, int fd)
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
	write(fd, "\n", 1);
}
