/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_to_string_bonus.c                           :+:      :+:    :+:   */
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
** Do bankers rounding and cut off for nines
*/

static int		round_off(t_dtoa *d, int digit, int *pi, char *buf)
{
	int			cmp;

	cmp = bigint_cmp(&(d->b), &(d->s));
	if (cmp > 0 || (cmp == 0 && digit & 1))
	{
		if (buf[(*pi) - 1] == '9')
		{
			while (buf[(*pi) - 1] == '9')
				(*pi)--;
			if ((*pi) == 0)
				return (TRUE);
		}
		++(buf[(*pi) - 1]);
	}
	while ((*pi) > 0 && buf[(*pi) - 1] == '0')
		(*pi)--;
	return (FALSE);
}

/*
** Convert bigint to string.
** then, do bankers roundin up.
*/

int				bigint_to_string(t_dtoa *d, int limit)
{
	char		*buf;
	int			i;
	int			digit;

	buf = d->buf;
	i = 0;
	while (1)
	{
		digit = bigint_quorem(&(d->b), &(d->s)) + '0';
		buf[i++] = digit;
		if (i >= limit)
			break ;
		if (!bigint_multadd(&(d->b), 10, 0))
			return (FALSE);
	}
	if (!bigint_lshift(&(d->b), 1))
		return (FALSE);
	if (round_off(d, digit, &i, buf))
	{
		free(buf);
		return (set_strval(d, "1", d->p10d + 2));
	}
	buf[i] = '\0';
	return (TRUE);
}
