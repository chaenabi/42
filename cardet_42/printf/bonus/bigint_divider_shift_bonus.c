/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_divider_shift_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:43:59 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:38 by smun             ###   ########.fr       */
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
