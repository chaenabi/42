/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_from_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:29:05 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:39 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int						bigint_from_int(t_bigint *b, int nb)
{
	if ((bigint_alloc(b, 1, FALSE)))
	{
		b->blockcnt = 1;
		b->block[0] = nb;
		return (TRUE);
	}
	return (FALSE);
}

static uint32_t			get_fraction(t_modf u)
{
	uint32_t			u1;

	u1 = u.i32[1] & 0xfffffu;
	if ((u.i32[1] >> 20) & 0x7ff)
		u1 |= (1u << 20);
	return (u1);
}

/*
** How does it work?
**
**  1. Delete the lowest zero bits through pushing out
**  2. Put 32 bits in each block from the bottom
*/

static void				substitute(t_dtoa *d, t_modf u)
{
	t_bigint			*b;
	int					bitindex;
	uint32_t			u1;
	uint32_t			u0;

	b = &(d->b);
	u1 = get_fraction(u);
	if ((u0 = u.i32[0]))
	{
		if ((bitindex = ft_sbit(u0, Side_Tail)))
			b->block[0] = (u0 >> bitindex) | u1 << (32 - bitindex);
		else
			b->block[0] = u0;
		b->block[1] = (u1 >> bitindex);
		b->blockcnt = b->block[1] ? 2 : 1;
	}
	else
	{
		bitindex = ft_sbit(u1, Side_Tail);
		b->block[0] = u1 >> bitindex;
		b->blockcnt = 1;
		bitindex += 32;
	}
}

static uint64_t			get_fraction64(t_modf u)
{
	return ((u.i & (1ull << 52) - 1) | (0x3ffull << 52));
}

int						bigint_from_double(t_dtoa *d, double dbl, int *pbits)
{
	t_bigint			*b;
	t_modf				u;

	b = &(d->b);
	u.f = dbl;
	if (!bigint_alloc(&(d->b), 1, FALSE))
		return (FALSE);
	substitute(d, u);
	do_logarithm(d, u);
	if ((u.i32[1] >> 20) & 0x7ff)
		*pbits = 52 - ft_sbit64(get_fraction64(u), Side_Tail) + 1;
	else
		*pbits = (32 * b->blockcnt) -
					ft_sbit(b->block[b->blockcnt - 1], Side_Head);
	return (TRUE);
}
