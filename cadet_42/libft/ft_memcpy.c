/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:52:33 by mylee             #+#    #+#             */
/*   Updated: 2020/12/22 22:52:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*result;
	unsigned char	*uc_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	result = dest;
	uc_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*result++ = *uc_src++;
	return (result);
}