/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_quorem_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:28:52 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static int		count_blocks_s(t_bigint *b, t_bigint *s)
{
	int			i;

	i = s->blockcnt - 1;
	while (i > 0 && !b->block[i - 1])
		i--;
	return (i);
}

static void		subtract_by_qmult(t_bigint *b, t_bigint *s, int quotient)
{
	uint64_t	borrow;
	uint64_t	carry;
	uint64_t	tmp;
	int			i;

	borrow = 0;
	carry = 0;
	i = 0;
	while (less_than(i, s->blockcnt))
	{
		tmp = s->block[i] * (uint64_t)quotient + carry;
		carry = tmp >> 32;
		tmp = b->block[i] - (tmp & 0xfffffffful) - borrow;
		borrow = tmp >> 32 & 1ul;
		b->block[i++] = tmp & 0xfffffffful;
	}
	if (!b->block[i - 1])
		b->blockcnt = count_blocks_s(b, s);
}

int				bigint_quorem(t_bigint *b, t_bigint *s)
{
	int			quotient;

	if (b->blockcnt < s->blockcnt)
		return (0);
	quotient = b->block[s->blockcnt - 1] / (s->block[s->blockcnt - 1] + 1);
	if (quotient)
		subtract_by_qmult(b, s, quotient);
	if (bigint_cmp(b, s) >= 0)
	{
		quotient++;
		subtract_by_qmult(b, s, 1);
	}
	return (quotient);
}
