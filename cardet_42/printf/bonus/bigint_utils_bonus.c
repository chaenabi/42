/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:54:42 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:57 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int						count_blocks(t_bigint *res)
{
	int					i;

	i = res->blocksmax;
	while (i >= 0 && !res->block[i - 1])
		i--;
	return (i);
}

static int				get_exponent_with_hb(t_dtoa *d, double dbl, int *pbi)
{
	t_modf				u;
	int					exp;
	int					bit;
	int					i;

	u.f = dbl;
	i = (d->b).blockcnt;
	bit = ft_sbit64(u.i, Side_Tail);
	if ((exp = (int)(((u.i >> 52) & 0x7ff))))
		*pbi = exp + bit + (53 - bit) - 1;
	else
		*pbi = exp + bit + (32 * i - ft_sbit((d->b).block[i - 1], Side_Head));
	return (exp);
}

/*
** Basic algorithm from dtoa.c by David M. Gay
**
** log(x)	~=~ log(1.5) + (x-1.5)/1.5
** log10(x)	 =  log(x) / log(10)
** 	~=~ log(1.5)/log(10) + (x-1.5)/(1.5*log(10))
** log10(d) = (i-Bias)*log(2)/log(10) + log10(d2)
**
** k = (i - Bias)*0.301029995663981
**	+ ( (d2-1.5)*0.289529654602168 + 0.176091259055681 );
** dbl = (bi > 32 ? (u.i32[1] << (64 - bi) | (u.i32[0] >> (bi - 32)))
**          : (u.i32[0] << (32 - bi)));
*/

void					do_logarithm(t_dtoa *d, t_modf u)
{
	t_modf				val;
	int					exp;
	int					bi;
	double				dbl;

	if ((exp = get_exponent_with_hb(d, u.f, &bi)))
	{
		val.i = (0x3ffULL << 52) | (u.i & ((1ull << 52) - 1));
		exp -= 1023;
		bi = exp;
	}
	else
	{
		dbl = (bi > 32 ? ((u.i << (64 - bi)) >> 32) : (u.i << (32 - bi)));
		val.f = (uint32_t)dbl;
		val.i -= (0x1fULL << 52);
		bi -= ((1023 + 52 - 1) + 1);
	}
	d->p2d = bi;
	d->p10d = ft_floor((val.f - 1.5) *
		0.289529654602168 + 0.1760912590558 + bi * 0.301029995663981);
}
