/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:42:07 by mylee             #+#    #+#             */
/*   Updated: 2020/12/27 00:48:15 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	dst = s;
	i = 0;
	while (i++ < n)
		*dst++ = 0;
}
