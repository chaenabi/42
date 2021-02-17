/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_lshift_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static void				do_shift(t_bigint *ret, t_bigint *b, int shift)
{
	uint32_t			tmp;
	int					i;
	int					b_unit;

	i = 0;
	tmp = 0;
	b_unit = shift / 32;
	if ((shift &= 31))
	{
		while (less_than(i, b->blockcnt))
		{
			ret->block[i + b_unit] = (b->block[i] << shift) | tmp;
			tmp = b->block[i++] >> (32 - shift);
		}
		ret->block[i + b_unit] = tmp;
	}
	else
	{
		while (less_than(i, b->blockcnt))
		{
			ret->block[i + b_unit] = b->block[i];
			i++;
		}
	}
}

int						bigint_lshift(t_bigint *b, int shift)
{
	t_bigint			tmp;

	if (!bigint_alloc(&tmp, b->blockcnt + (shift / 32) + 1, TRUE))
		return (FALSE);
	do_shift(&tmp, b, shift);
	tmp.blockcnt = count_blocks(&tmp);
	bigint_replace(b, &tmp);
	return (TRUE);
}
