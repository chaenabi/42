/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_fge_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:09:12 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:03:29 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

static void				padding(t_printf *p, t_format *e, int side, int len)
{
	if (side == Side_Head)
	{
		if (e->flags & Flags_PaddingByZero)
		{
			if (e->sign)
				ft_putchar_pf(p, e->sign);
			if (!(e->flags & Flags_LeftJustify))
				ft_putchar_len_pf(p, '0', len);
		}
		else
		{
			if (!(e->flags & Flags_LeftJustify))
				ft_putchar_len_pf(p, ' ', len);
			if (e->sign)
				ft_putchar_pf(p, e->sign);
		}
	}
	else
	{
		if (e->flags & Flags_LeftJustify)
			ft_putchar_len_pf(p, ' ', len);
	}
}

static void				print_float(t_printf *p, t_format *e, char *buf)
{
	int					len;

	len = ft_strlen(buf);
	len = e->width - len - (e->sign ? 1 : 0);
	padding(p, e, Side_Head, len);
	ft_putstr_pf(p, buf);
	padding(p, e, Side_Tail, len);
}

static t_bool			is_match(t_format *e, const char *f)
{
	return (ft_strchr(f, e->specifier) ? TRUE : FALSE);
}

void					print_fge(t_printf *p, t_format *e, va_list *args)
{
	char				*buf;
	double				val;
	int					alt;
	int					up;

	val = get_arg_float(e, args);
	alt = e->flags & Flags_Alternative;
	up = ('A' <= e->specifier && e->specifier <= 'Z');
	buf = NULL;
	if (is_match(e, "fF"))
		buf = ft_convert_f(val, e->precision, alt);
	else if (is_match(e, "eE"))
		buf = ft_convert_e(val, e->precision, up, alt);
	else if (is_match(e, "gG"))
		buf = ft_convert_g(val, e->precision, up, alt);
	if (buf != NULL)
	{
		print_float(p, e, buf);
		free(buf);
	}
}
