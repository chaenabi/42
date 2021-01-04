/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:14:36 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:03:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

char				*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return (NULL);
	while (1)
	{
		if (*s == (char)c)
			return ((char*)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

int					ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int					ft_strlen(const char *ch)
{
	int				l;

	l = 0;
	if (ch)
	{
		while (ch[l])
			l++;
	}
	return (l);
}

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			slen;
	size_t			cpylen;

	slen = ft_strlen(src);
	if (dstsize > 0)
	{
		cpylen = dstsize - 1;
		if (slen < dstsize)
			cpylen = slen;
		ft_memcpy(dst, src, cpylen);
		if (dst)
			dst[cpylen] = '\0';
	}
	return (slen);
}

char				*ft_strdup(const char *s1)
{
	int				len;
	char			*s;

	len = ft_strlen(s1);
	if ((s = (char*)malloc(len + 1)))
		ft_strlcpy(s, s1, len + 1);
	return (s);
}
