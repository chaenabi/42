/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:50:35 by mylee             #+#    #+#             */
/*   Updated: 2020/12/22 22:57:14 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*result;
	unsigned char	*uc_src;
	unsigned char	find;
	size_t			i;

	result = dest;
	uc_src = (unsigned char *)src;
	find = c;
	i = 0;
	while (i < n)
	{
		result[i] = uc_src[i];
		if (result[i] == find)
			return (dest + (i + 1));
		i++;
	}
	return (0);
}
