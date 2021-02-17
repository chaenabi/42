/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int			less_than(int a, int b)
{
	return (a == 0 || a < b);
}

int			ft_sbit(uint32_t i, int side)
{
	int		ret;

	if (i == 0)
		return (32);
	ret = 0;
	if (side == Side_Tail)
	{
		while ((i & 1) == 0)
		{
			ret++;
			i >>= 1;
		}
	}
	if (side == Side_Head)
	{
		while ((i & 0x80000000u) == 0)
		{
			ret++;
			i <<= 1;
		}
	}
	return (ret);
}

int			ft_sbit64(uint64_t i, int side)
{
	int		ret;

	if (i == 0)
		return (64);
	ret = 0;
	if (side == Side_Tail)
	{
		while ((i & 1) == 0)
		{
			ret++;
			i >>= 1;
		}
	}
	if (side == Side_Head)
	{
		while ((i & 0x8000000000000000ull) == 0)
		{
			ret++;
			i <<= 1;
		}
	}
	return (ret);
}

int			set_strval(t_dtoa *d, const char *s, int decpt)
{
	d->decpt = decpt;
	return ((d->buf = ft_strdup(s)) ? TRUE : FALSE);
}

int			process_special_values(t_dtoa *d, double dd)
{
	if (ft_isnan(dd))
		return (set_strval(d, "nan", 9999));
	if (ft_isinf(dd))
		return (set_strval(d, "inf", 9999));
	if (dd == 0)
		return (set_strval(d, "0", 1));
	return (FALSE);
}
