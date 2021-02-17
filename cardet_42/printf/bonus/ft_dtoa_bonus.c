/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

/*
** Make divider with rounding dividend.
**
** we want ensured 4 leading zero bits. (= shift left)
** then shift left by s2.
** now we can get how many it has leading zero bits.
**
** finally, shift left by the value, to remove leading zero bits.
*/

static t_bool	make_divider(t_dtoa *d, int b2, int s2, t_bool *prcmp)
{
	int			m;

	m = bigint_get_divider_shift(&(d->s), s2);
	if (b2 + m > 0 && !bigint_lshift(&(d->b), b2 + m))
		return (FALSE);
	if (s2 + m > 0 && !bigint_lshift(&(d->s), s2 + m))
		return (FALSE);
	if (bigint_cmp(&(d->b), &(d->s)) < 0)
	{
		if (!bigint_multadd(&(d->b), 10, 0))
			return (FALSE);
		*prcmp = TRUE;
	}
	else
		*prcmp = FALSE;
	return (TRUE);
}

/*
** 10^i = 2^i * 5^i.
**
** By using it, make a divider so that the digits match the bigint.
** Then, multiply dividend by a certain amount for match divider if necessary.
**
** b2 = 2 powers for dividend.
** s2 = 2 powers for divider
** To match for computing division.
**
** b5 = 5 powers for dividend.
** s5 = 5 powers for divdider.
**
** p10d > 0: make divider as large by adding log10 to s2
** p10d < 0: make dividend as small by subtracting log10 from b2
**
** mode3: precision + log10 + 1
**
** finally, when b2 > 0 && s2 > 0,
** make smaller one of b2 and s2 to zero.
** and subtract the other one by it.
*/

static t_bool	prepare_for_powmult(t_dtoa *d, int bits, t_bool *prcmp)
{
	int			b2;
	int			s2;
	int			b5;
	int			s5;

	bits -= (d->p2d + 1);
	b2 = (bits - d->p2d > 0 ? 0 : -bits);
	s2 = (bits - d->p2d > 0 ? bits : 0);
	b5 = (d->p10d >= 0 ? 0 : -(d->p10d));
	s5 = (d->p10d >= 0 ? d->p10d : 0);
	if (d->p10d >= 0)
		s2 += d->p10d;
	else
		b2 -= d->p10d;
	if (b2 > 0 && s2 > 0)
	{
		d->p2d = ft_min(b2, s2);
		b2 -= d->p2d;
		s2 -= d->p2d;
	}
	return (bigint_pow5mult(&(d->b), ft_max(b5, 0)) &&
			bigint_from_int(&(d->s), 1) &&
			bigint_pow5mult(&(d->s), ft_max(s5, 0)) &&
			make_divider(d, b2, s2, prcmp));
}

static int		dtoa_internal(t_dtoa *d, int ndigits)
{
	int			limit;

	limit = (ndigits + d->p10d + 1);
	if (d->mode == 2)
		limit = (ndigits <= 0 ? 1 : (1 + ndigits));
	if (limit <= 0 && d->mode == 3)
	{
		if (!bigint_multadd(&(d->s), 5, 0))
			return (FALSE);
		if (limit < 0 || bigint_cmp(&(d->b), &(d->s)) <= 0)
			return (set_strval(d, "", -ndigits));
		else
			return (set_strval(d, "1", d->p10d + 2));
	}
	if ((d->b).block[0] == 0 && (d->b).blockcnt <= 1)
		return (set_strval(d, "0", d->p10d + 1));
	d->decpt = d->p10d + 1;
	if ((d->buf = malloc(1 + limit)) && bigint_to_string(d, limit))
		return (TRUE);
	if (d->buf)
		free(d->buf);
	d->buf = NULL;
	return (FALSE);
}

/*
** mode
**   2: for %g, %e (caution! for %g, precision should be decremented once.)
**   3: for %f
**
** ndigits = precision
*/

char			*ft_dtoa(double dd, int mode, int ndigits, int *decpt)
{
	t_dtoa		d;
	int			bits;
	t_bool		prcmp;

	ft_bzero(&d, sizeof(t_dtoa));
	d.mode = mode;
	if (ft_isnan(dd) || ft_isinf(dd) || dd == 0)
	{
		if (!process_special_values(&d, dd))
			return (NULL);
	}
	else
	{
		if (!bigint_from_double(&d, dd, &bits))
			return (NULL);
		if (prepare_for_powmult(&d, bits, &prcmp))
		{
			if (prcmp == TRUE)
				(d.p10d)--;
			dtoa_internal(&d, ndigits);
		}
	}
	*decpt = d.decpt;
	bigint_free(d.b.block, d.s.block);
	return (d.buf);
}
