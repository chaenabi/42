/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float_g_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

static t_bool		is_scientific(int decpt, int prec)
{
	if (decpt <= -4)
		return (TRUE);
	if (prec > 0)
		return (prec < decpt);
	return (prec < decpt - 1);
}

static void			fill_digits(t_cvt_buf *cbuf, char *d, int decpt)
{
	int				len;
	int				bufreadbytes;

	len = (int)ft_strlen(d);
	if (cbuf->scientific || decpt <= 0)
		cbuf->i = 1;
	else if (decpt > len)
		cbuf->i = len;
	else
		cbuf->i = decpt;
	bufreadbytes = 0;
	if (decpt > 0 || cbuf->scientific)
	{
		ft_memcpy(cbuf->buf, d, cbuf->i);
		bufreadbytes += cbuf->i;
	}
	if (!cbuf->scientific && decpt > len)
		cbuf->i += (decpt - len);
	cbuf->buf[(cbuf->i)++] = '.';
	if (!cbuf->scientific && decpt < 0)
		cbuf->i += -decpt;
	ft_memcpy(&cbuf->buf[cbuf->i], &d[bufreadbytes], len - bufreadbytes);
	cbuf->i += len - bufreadbytes;
}

static void			make_short(t_cvt_buf *cbuf, int prec, int decpt, int opt)
{
	int				i;
	int				digits;

	digits = prec;
	if (!cbuf->scientific)
		digits += (decpt > 0 ? 0 : 1 - decpt);
	i = (int)ft_strlen(cbuf->buf) - 1;
	while (i > 0 && cbuf->buf[i] == '0' && (!opt || i - digits > 0))
		i--;
	if (i > 0 && cbuf->buf[i] == '.' && !opt)
		i--;
	cbuf->i = i + 1;
	cbuf->buf[cbuf->i] = '\0';
}

static void			fill_scientific(t_cvt_buf *cbuf, int decpt, int upper)
{
	if (!cbuf->scientific)
		return ;
	cbuf->buf[(cbuf->i)++] = upper ? 'E' : 'e';
	cbuf->buf[(cbuf->i)++] = decpt > 0 ? '+' : '-';
	fill_scale(&cbuf->buf[(cbuf->i)++], decpt - 1);
	if ((decpt - 1) / 100)
		cbuf->buf[cbuf->i + 2] = '\0';
	else
		cbuf->buf[cbuf->i + 1] = '\0';
}

char				*ft_convert_g(double d, int prec, int upper, int optional)
{
	t_cvt_buf		cbuf;
	char			*digits;
	int				decpt;
	int				buflen;

	cbuf.buf = NULL;
	if (prec < 0)
		prec = 6;
	if ((digits = ft_dtoa(d, 2, prec - 1, &decpt)))
	{
		if (decpt == 9999)
			return (digits);
		buflen = (ft_abs(decpt) + prec + (decpt <= 0)) + 2;
		if (is_scientific(decpt, prec))
			buflen += (4 + (ft_abs(decpt) >= 100));
		if (alloc_cvt_buf(&cbuf, buflen))
		{
			cbuf.scientific = is_scientific(decpt, prec);
			fill_digits(&cbuf, digits, decpt);
			make_short(&cbuf, prec, decpt, optional);
			fill_scientific(&cbuf, decpt, upper);
		}
		free(digits);
	}
	return (cbuf.buf);
}
