/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_mult_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:06:09 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:48 by smun             ###   ########.fr       */
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
