/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** Parse Flags ('-', '0', '#', ' ', '+') into t_format structure.
*/

void		parse_flags(t_printf *p, t_format *e)
{
	int		c;

	while (ft_strchr("-0# +", *(p->format)))
	{
		c = *(p->format++);
		if (c == '-')
			e->flags |= Flags_LeftJustify;
		else if (c == '0')
			e->flags |= Flags_PaddingByZero;
		else if (c == '#')
			e->flags |= Flags_Alternative;
		else if (c == ' ')
			e->flags |= Flags_Space;
		else if (c == '+')
			e->flags |= Flags_Sign;
	}
}

/*
** ** Parse Width ('*') into t_format structure.
*/

void		parse_width(t_printf *p, t_format *e)
{
	if (*(p->format) == '*')
	{
		e->width_mode = Number_Defined;
		e->width = va_arg(*(p->args), int);
		if (e->width < 0)
		{
			e->width = -(e->width);
			e->flags |= Flags_LeftJustify;
		}
		p->format++;
	}
	else
	{
		while (ft_isdigit(*(p->format)))
		{
			e->width_mode = Number_Defined;
			e->width = e->width * 10 + (*(p->format++) - '0');
		}
	}
}

/*
** Parse Precision ('*', '.') into t_format structure.
*/

void		parse_precision(t_printf *p, t_format *e)
{
	if (*(p->format) == '.')
	{
		p->format++;
		if (*(p->format) == '*')
		{
			e->precision_mode = Number_Defined;
			e->precision = va_arg(*(p->args), int);
			if (e->precision < 0)
			{
				e->precision = 0;
				e->precision_mode = Number_None;
			}
			p->format++;
		}
		else
		{
			e->precision_mode = Number_Defined;
			e->precision = 0;
			while (ft_isdigit(*(p->format)))
				e->precision = e->precision * 10 + (*(p->format++) - '0');
		}
	}
}

/*
** Parse Length Specifier ('l', 'll', 'h', 'hh')
*/

void		parse_length(t_printf *p, t_format *e)
{
	int		c;

	if (ft_strchr("lh", *(p->format)))
	{
		c = *(p->format++);
		e->length = c == 'l' ? Length_L : Length_H;
		if (ft_strchr("lh", *(p->format)))
		{
			c = *(p->format++);
			if (e->length == Length_L && c == 'l')
				e->length = Length_LL;
			if (e->length == Length_H && c == 'h')
				e->length = Length_HH;
		}
	}
}

/*
** Parse Specifier ('c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%',
** 'o', 'n', 'e', 'E', 'f', 'F', 'g', 'G', 'D')
** into t_format structure.
*/

void		parse_specifier(t_printf *p, t_format *e)
{
	if (ft_strchr("cspdiuxX%oneEfFgGD", *(p->format)))
	{
		e->specifier = *(p->format);
		if (e->specifier == 'D')
			e->specifier = 'd';
		if (ft_strchr("eEfFgG", e->specifier) &&
			e->precision_mode == Number_None)
			e->precision = 6;
		p->format++;
	}
}
