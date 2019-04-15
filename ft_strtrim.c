/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:09:12 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/30 19:26:16 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtrim(char const *s)
{
	int		step;
	int		start;
	int		finish;
	char	*copy_s;

	if (s == NULL)
		return (0);
	step = 0;
	while (s[step] == ' ' || s[step] == '\t' || s[step] == '\n')
		step++;
	if (s[step] == '\0')
		return (ft_strdup((char*)s + step));
	start = step;
	while (s[step++])
		if ((s[step] >= 33 && s[step] <= 126) && (s[step + 1] != ' ' ||
				s[step + 1] != '\t' || s[step + 1] != '\n'))
			finish = step;
	step = 0;
	copy_s = (char*)malloc(sizeof(char) * (finish - start) + 2);
	if (copy_s == 0)
		return (0);
	while (start <= finish)
		copy_s[step++] = s[start++];
	copy_s[step] = '\0';
	return (copy_s);
}
