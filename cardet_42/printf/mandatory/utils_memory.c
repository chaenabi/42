/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:11:53 by mylee             #+#    #+#             */
/*   Updated: 2021/02/16 01:21:01 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void					ft_bzero(void *s, size_t n)
{
	unsigned char		*dest;
	size_t				*dest_large;
	size_t				i;

	dest = (unsigned char*)s;
	i = n % sizeof(size_t);
	while (i--)
		*(dest++) = 0;
	dest_large = (size_t*)dest;
	i = n / sizeof(size_t);
	while (i--)
		*(dest_large++) = 0;
}

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*source = (const unsigned char*)src;
	unsigned char		*dest;
	size_t				*source_large;
	size_t				*dest_large;
	size_t				i;

	if (src || dst)
	{
		dest = (unsigned char*)dst;
		if ((i = n % sizeof(size_t)))
		{
			while (i--)
				*(dest++) = *(source++);
		}
		if ((i = n / sizeof(size_t)))
		{
			source_large = (size_t*)source;
			dest_large = (size_t*)dest;
			while (i--)
				*(dest_large++) = *(source_large++);
		}
	}
	return (dst);
}

void					*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*dest;
	size_t				*dest_large;
	size_t				data;
	size_t				i;

	data = (c & 0xff);
	data |= (data << 8);
	data |= (data << 16);
	if (sizeof(size_t) >= 8)
		data |= (data << 32);
	dest = (unsigned char*)b;
	i = len % sizeof(size_t);
	while (i--)
		*(dest++) = c;
	dest_large = (size_t*)dest;
	i = len / sizeof(size_t);
	while (i--)
		*(dest_large++) = data;
	return (b);
}
