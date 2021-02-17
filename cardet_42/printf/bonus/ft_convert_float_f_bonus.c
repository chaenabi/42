/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float_f_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

static int			calc_buffer_length(int decpt, int prec, int forced_point)
{
	int				buflen;

	if (decpt > 0)
		buflen = (int)(prec + decpt);
	else
		buflen = (int)(1 + prec);
	if (prec > 0 || forced_point)
		buflen++;
	return (buflen);
}

static void			fill_integer_part(char *ret, char *buf, int decpt)
{
	size_t			len;

	if (decpt > 0)
	{
		len = ft_strlen(buf);
		if (len < (size_t)decpt)
		{
			ft_memcpy(ret, buf, len);
			ft_memset(&ret[len], '0', decpt - len);
		}
		else
			ft_memcpy(ret, buf, decpt);
	}
	else
		ret[0] = '0';
}

static void			put_decimal_point(char *ret, int decpt, int prec, int point)
{
	if (point || prec > 0)
	{
		if (decpt > 0)
			ret[decpt] = '.';
		else
			ret[1] = '.';
	}
}

static void			fill_decimal_part(char *ret, char *buf, int prec, int decpt)
{
	size_t			len;

	if (prec <= 0)
		return ;
	len = ft_strlen(buf);
	if (decpt > 0)
	{
		ft_memset(&ret[1 + decpt], '0', prec);
		if (len > (size_t)decpt)
			ft_memcpy(&ret[1 + decpt], &buf[decpt], len - decpt);
	}
	else
	{
		ft_memset(&ret[2], '0', prec);
		ft_memcpy(&ret[2 - decpt], &buf[0], len);
	}
}

char				*ft_convert_f(double d, int prec, int point)
{
	char			*ret;
	char			*buf;
	int				decpt;
	int				buflen;

	ret = NULL;
	if (prec < 0)
		prec = 6;
	if ((buf = ft_dtoa(d, 3, prec, &decpt)))
	{
		if (decpt == 9999)
			return (buf);
		buflen = calc_buffer_length(decpt, prec, point);
		if ((ret = malloc(1 + buflen)))
		{
			fill_integer_part(ret, buf, decpt);
			put_decimal_point(ret, decpt, prec, point);
			fill_decimal_part(ret, buf, prec, decpt);
			ret[buflen] = '\0';
		}
		free(buf);
	}
	return (ret);
}
