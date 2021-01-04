/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_pdiuopx_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:38:44 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:03:33 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

static void			padding(t_printf *p, t_format *e, int side, int len)
{
	if (side == Side_Head)
	{
		if (e->flags & Flags_PaddingByZero)
		{
			if (e->sign)
				ft_putchar_pf(p, e->sign);
			ft_putstr_pf(p, e->prefix);
			if (!(e->flags & Flags_LeftJustify))
				ft_putchar_len_pf(p, '0', len);
		}
		else
		{
			if (!(e->flags & Flags_LeftJustify))
				ft_putchar_len_pf(p, ' ', len);
			if (e->sign)
				ft_putchar_pf(p, e->sign);
			ft_putstr_pf(p, e->prefix);
		}
	}
	else
	{
		if (e->flags & Flags_LeftJustify)
			ft_putchar_len_pf(p, ' ', len);
	}
}

static void			print_integer(t_printf *p, t_format *e, char *buf, int len)
{
	int				width;
	int				prec;
	int				plen;

	plen = ft_strlen(e->prefix);
	if (len > e->precision)
		width = e->width - plen - len - (e->sign ? 1 : 0);
	else
		width = e->width - plen - e->precision - (e->sign ? 1 : 0);
	prec = e->precision - len;
	padding(p, e, Side_Head, width);
	ft_putchar_len_pf(p, '0', prec);
	ft_putstr_pf(p, buf);
	padding(p, e, Side_Tail, width);
}

static void			convert_integer(char *buf, int len, uint64_t val, int base)
{
	const char		*b = "0123456789abcdef0123456789ABCDEF";
	int				upper;

	upper = 0;
	if (base < 0)
	{
		base = 16;
		upper = 16;
	}
	buf[--len] = '\0';
	if (val == 0)
		buf[--len] = b[0];
	else
	{
		while (val > 0)
		{
			buf[--len] = b[upper + (val % base)];
			val /= base;
		}
	}
	buf[--len] = 0x7f;
}

static const char	*get_prefix(t_format *e, uint64_t val, char *buf)
{
	const char		*prefix;

	prefix = NULL;
	if (e->specifier == 'p')
		prefix = "0x";
	else if (e->flags & Flags_Alternative && e->specifier == 'o')
	{
		if ((!e->precision && val == 0) || e->precision > ft_strlen(buf))
			prefix = NULL;
		else
			prefix = "0";
	}
	else if (e->flags & Flags_Alternative)
	{
		if (val == 0)
			prefix = NULL;
		else if (e->specifier == 'x')
			prefix = "0x";
		else if (e->specifier == 'X')
			prefix = "0X";
	}
	return (prefix);
}

void				print_pdiuopx(t_printf *p, t_format *e, va_list *args)
{
	char			buf[64];
	int				i;
	uint64_t		val;

	i = 1;
	ft_bzero(buf, sizeof(buf));
	val = get_arg_int(e, args);
	if (ft_strchr("diu", e->specifier))
		convert_integer(buf, sizeof(buf), val, 10);
	else if (ft_strchr("o", e->specifier))
		convert_integer(buf, sizeof(buf), val, 8);
	else if (ft_strchr("xp", e->specifier))
		convert_integer(buf, sizeof(buf), val, 16);
	else if (ft_strchr("X", e->specifier))
		convert_integer(buf, sizeof(buf), val, -16);
	while (buf[i - 1] != 0x7f)
		i++;
	if (e->precision_mode && e->precision == 0 && val == 0)
		i = sizeof(buf) - 1;
	e->prefix = get_prefix(e, val, &buf[i]);
	print_integer(p, e, &buf[i], ft_strlen(&buf[i]));
}
