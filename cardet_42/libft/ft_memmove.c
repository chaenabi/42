/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:57:51 by mylee             #+#    #+#             */
/*   Updated: 2020/12/22 22:57:54 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*result;
	unsigned char	*uc_src;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		result = (unsigned char *)dest;
		uc_src = (unsigned char *)src;
		while (n--)
			*result++ = *uc_src++;
	}
	else
	{
		result = (unsigned char *)dest + (n - 1);
		uc_src = (unsigned char *)src + (n - 1);
		while (n--)
			*result-- = *uc_src--;
	}
	return (dest);
}
