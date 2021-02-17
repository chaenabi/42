/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_divider_shift_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** 	if (r < 0)
** 		return (32 + r);
** 	return (r);
*/

int				bigint_get_divider_shift(t_bigint *b, int p2)
{
	int			r;

	r = ft_sbit(b->block[b->blockcnt - 1], Side_Head) - 4;
	if (p2 > 0)
		r -= p2;
	return (r & 31);
}
