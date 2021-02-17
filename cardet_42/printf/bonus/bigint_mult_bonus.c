/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_mult_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int						bigint_mult(t_bigint *a, t_bigint *b)
{
	t_bigint			res;
	uint64_t			carry;
	uint64_t			tmp;
	int					i;
	int					j;

	if (!bigint_alloc(&res, a->blockcnt + b->blockcnt, TRUE))
		return (FALSE);
	i = 0;
	while (i < a->blockcnt)
	{
		j = 0;
		carry = 0;
		while (j < b->blockcnt)
		{
			tmp = b->block[j];
			tmp = res.block[i + j] + tmp * a->block[i] + carry;
			carry = tmp >> 32;
			res.block[i + (j++)] = tmp & 0xfffffffful;
		}
		res.block[(i++) + j] = carry;
	}
	res.blockcnt = count_blocks(&res);
	bigint_replace(a, &res);
	return (TRUE);
}
