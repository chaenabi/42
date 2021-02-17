/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_cmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int						bigint_cmp(t_bigint *a, t_bigint *b)
{
	int					i;

	if (a->blockcnt != b->blockcnt)
		return (a->blockcnt < b->blockcnt ? -1 : 1);
	i = a->blockcnt;
	while (--i >= 0)
		if (a->block[i] != b->block[i])
			return (a->block[i] < b->block[i] ? -1 : 1);
	return (0);
}
