/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float_buf_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

int				alloc_cvt_buf(t_cvt_buf *cbuf, int buflen)
{
	if ((cbuf->buf = malloc(1 + buflen)))
	{
		cbuf->i = 0;
		ft_memset(cbuf->buf, '0', buflen);
		cbuf->buf[buflen] = '\0';
		return (TRUE);
	}
	cbuf->buf = NULL;
	return (FALSE);
}

static char		*conv(char *b, int num)
{
	if (num / 10)
		b = conv(b, num / 10);
	*b = (num % 10) + '0';
	return (b + 1);
}

static int		digitlen(int num)
{
	if (num / 100)
		return (3);
	return (num / 10 ? 2 : 1);
}

void			fill_scale(char *ret, int decpt)
{
	int			elen;
	int			scalestrlen;

	elen = digitlen(decpt);
	scalestrlen = elen > 2 ? 3 : 2;
	ft_memset(ret, '0', scalestrlen);
	conv(&ret[scalestrlen - elen], ft_abs(decpt));
}
