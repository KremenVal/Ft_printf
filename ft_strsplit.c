/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:53:40 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 17:40:05 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	num_words(char const *s, char c)
{
	int count;
	int step;

	count = 0;
	step = -1;
	while (s[++step])
		if (s[step] != c)
		{
			while (s[step] != c && s[step])
				step++;
			count++;
		}
	return (count);
}

static int	co(char const *s, char c)
{
	int count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	return (count);
}

static char	*ret_val(char const *s, int step, int len, char c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	while (s[step] != c && s[step])
	{
		res[i] = s[step];
		i++;
		step++;
	}
	res[i] = '\0';
	return (res);
}

char		**ft_strsplit(char	const *s, char c)
{
	int		len_wrd;
	int		step;
	int		m;
	int		cnt_wrd;
	char	**answer;

	if (s == NULL)
		return (0);
	step = -1;
	m = 0;
	cnt_wrd = num_words(s, c);
	answer = (char**)malloc(sizeof(char*) * cnt_wrd + 1);
	if (answer == 0)
		return (0);
	while (s[++step])
		if (s[step] != c && s[step])
		{
			len_wrd = co((char*)s + step, c);
			answer[m] = (char*)malloc(sizeof(char) * (len_wrd + 1));
			answer[m++] = ret_val(s, step, len_wrd, c);
			s = (char*)s + step + len_wrd;
			step = -1;
		}
	answer[m] = NULL;
	return (answer);
}
