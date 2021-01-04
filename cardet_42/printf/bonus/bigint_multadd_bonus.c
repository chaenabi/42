/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_multadd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 09:20:20 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:49 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static void			multadd_eachblock(uint32_t *block, int m, uint64_t *pcarry)
{
	uint64_t		temp;

	temp = (*block) * (uint64_t)m + (*pcarry);
	*pcarry = temp >> 32;
	*block = (uint32_t)(temp & 0xfffffffful);
}

int					bigint_multadd(t_bigint *b, int m, int a)
{
	uint64_t		carry;
	int				i;

	carry = a;
	i = 0;
	while (less_than(i, b->blockcnt))
		multadd_eachblock(&b->block[i++], m, &carry);
	if (carry)
	{
		if (!bigint_ensure(b, b->blockcnt + 1))
			return (FALSE);
		b->block[(b->blockcnt)++] = carry;
	}
	return (TRUE);
}
