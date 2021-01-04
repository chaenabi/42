/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float_e_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:57:16 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:03:01 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

static int			get_exponent_length(int decpt)
{
	return (decpt / 100 != 0 ? 3 : 2);
}

static int			calc_buffer_length(int decpt, int prec, int forced_point)
{
	int				buflen;

	buflen = 1 + prec + 1 + 1 + get_exponent_length(decpt);
	if (forced_point || prec > 0)
		buflen++;
	return (buflen);
}

static void			fill_digits(char *ret, char *buf, int prec, int point)
{
	size_t			len;

	len = ft_strlen(buf);
	ret[0] = (len ? buf[0] : '0');
	ret[1] = '.';
	ft_memset(&ret[1 + point], '0', prec);
	if (len > 1)
		ft_memcpy(&ret[1 + point], &buf[1], len - 1);
}

char				*ft_convert_e(double d, int prec, int upper, int point)
{
	char			*ret;
	char			*buf;
	int				decpt;
	int				buflen;

	ret = NULL;
	if (prec < 0)
		prec = 6;
	point = prec > 0 || point;
	if ((buf = ft_dtoa(d, 2, prec, &decpt)))
	{
		if (decpt == 9999)
			return (buf);
		buflen = calc_buffer_length(decpt, prec, point);
		if ((ret = malloc(1 + buflen)))
		{
			fill_digits(ret, buf, prec, point);
			ret[1 + point + prec] = upper ? 'E' : 'e';
			ret[1 + point + prec + 1] = (decpt - 1) < 0 ? '-' : '+';
			fill_scale(&ret[1 + point + prec + 1 + 1], decpt - 1);
			ret[buflen] = '\0';
		}
		free(buf);
	}
	return (ret);
}
