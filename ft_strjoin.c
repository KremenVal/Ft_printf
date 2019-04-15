/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:05:35 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/28 22:13:09 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_res;
	int		step;
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		step = -1;
		i = -1;
		len_res = ft_strlen(s1) + ft_strlen(s2);
		result = (char*)malloc(sizeof(char) + len_res + 1);
		if (result == 0)
			return (0);
		while (step < len_res)
		{
			while (s1[++step])
				result[step] = s1[step];
			while (s2[++i])
				result[step++] = s2[i];
		}
		result[step] = '\0';
		return (result);
	}
	return (0);
}
