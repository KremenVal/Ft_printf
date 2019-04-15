/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:36:48 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 16:37:50 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcap(char *str)
{
	char	*ans;
	int		i;

	i = 0;
	ans = ft_strtrim(str);
	while (ans[i])
	{
		if (ans[i] >= 65 && ans[i] <= 90)
			ans[i] += 32;
		i++;
	}
	i = -1;
	if (ans[i + 1] >= 97 && ans[i] <= 122)
		ans[i + 1] -= 32;
	while (ans[++i])
		if (ans[i] == '.')
		{
			while (ans[i] < 47 || (ans[i] > 57 &&
						ans[i] < 97) || ans[i] > 122)
				i++;
			if (ans[i] >= 97 && ans[i] <= 122)
				ans[i] -= 32;
		}
	ans[i] = '\0';
	return (ans);
}
