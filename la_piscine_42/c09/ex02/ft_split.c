/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:55:45 by mylee             #+#    #+#             */
/*   Updated: 2020/12/09 10:41:36 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_find_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		++sep;
	}
	return (0);
}

int			ft_wc(char *str, char *sep)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		if (!ft_find_sep(*str, sep))
		{
			cnt++;
			while (*str && !ft_find_sep(*str, sep))
				str++;
		}
		str++;
	}
	return (cnt);
}

void		ft_strcpy(char *dst, char *src, char *n)
{
	while (src < n)
		*(dst++) = *(src++);
	*dst = 0;
}

char		**ft_split(char *str, char *sep)
{
	char	**array;
	char	*src;
	int		i;

	array = (char **)malloc(sizeof(char *) * ft_wc(str, sep) + 1);
	i = 0;
	while (*str)
	{
		if (!ft_find_sep(*str, sep))
		{
			src = str;
			while (*str && !ft_find_sep(*str, sep))
				++str;
			array[i] = (char *)malloc(str - src + 1);
			ft_strcpy(array[i++], src, str);
		}
		++str;
	}
	array[i] = 0;
	return (array);
}
