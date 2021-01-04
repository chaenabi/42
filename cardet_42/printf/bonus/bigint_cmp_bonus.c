/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_cmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:14:25 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:36 by smun             ###   ########.fr       */
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
