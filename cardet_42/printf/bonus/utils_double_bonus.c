/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_double_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:52:03 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:03:38 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int					ft_isinf(double nb)
{
	t_modf			u;
	int				exp;

	u.f = nb;
	exp = (int)((u.i >> 52) & 0x7ff) - 0x3ff;
	return (exp == 0x400 && (u.i << 12) == 0);
}

int					ft_isnan(double nb)
{
	t_modf			u;
	int				exp;

	u.f = nb;
	exp = (int)((u.i >> 52) & 0x7ff) - 0x3ff;
	return (exp == 0x400 && (u.i << 12) != 0);
}

/*
** Reference: sysdeps/ieee754/dbl-64/wordsize-64/s_floor.c
**            https://en.wikipedia.org/wiki/Floor_and_ceiling_functions
**            http://www.secmem.org/blog/2020/06/11/float-2/
**
** 1. exp < 0
**   = No integer part (0.xxxxx or -0.xxxxx)
**     -> positive: 0
**     -> negative: -1
**
** 2. exp >= 0
**   = Fill zero bits where starts decimal point.
*/

static int64_t		truncate_decimal_bits(int exp, int64_t i)
{
	uint64_t		mask;

	mask = (1ULL << (52 - exp)) - 1;
	if ((i & mask) == 0)
		return (i);
	i += (i < 0) * (1ULL << (52 - exp));
	i &= (~mask);
	return (i);
}

/*
** (uint64_t) (0x3ffULL << 52) | (1ULL << 63) = (double) (-1.0)
*/

double				ft_floor(double x)
{
	int64_t			i;
	int				exp;

	if (ft_isnan(x) || ft_isinf(x))
		return (x + x);
	*(double*)(&i) = x;
	exp = ((i >> 52) & 0x7ff) - 0x3ff;
	if (exp < 52)
	{
		if (exp < 0)
		{
			if (i > 0)
				i = 0;
			else if (i & ((1ULL << 63) - 1))
				i = (0x3ffULL << 52) | (1ULL << 63);
		}
		else
			i = truncate_decimal_bits(exp, i);
		*(int64_t*)(&x) = i;
	}
	return (x);
}

int					ft_signbit(double x)
{
	uint64_t		i;

	*((double*)(&i)) = x;
	return (i >> 63u);
}
