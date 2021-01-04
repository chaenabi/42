/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_pow5mult_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:14:19 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:51 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int			pow5(int k)
{
	if (k == 1)
		return (5);
	else if (k == 2)
		return (25);
	else if (k == 3)
		return (125);
	return (1);
}

int					bigint_pow5mult(t_bigint *b, int k)
{
	t_bigint		p;

	if ((k & 3) && !bigint_multadd(b, pow5(k & 3), 0))
		return (FALSE);
	if (!(k >>= 2))
		return (TRUE);
	if (!bigint_from_int(&p, 625))
		return (FALSE);
	while (1)
	{
		if ((k & 1) && !bigint_mult(b, &p))
			return (FALSE);
		if (!(k >>= 1))
			break ;
		if (!bigint_mult(&p, &p))
			return (FALSE);
	}
	return (TRUE);
}
