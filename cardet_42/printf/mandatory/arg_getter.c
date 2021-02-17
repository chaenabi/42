/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:33:23 by mylee             #+#    #+#             */
/*   Updated: 2021/02/15 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static uint64_t		arg_int(t_format *elem, size_t size, uint64_t num)
{
	uint64_t	mask;

	mask = ~0ull;
	if (size < sizeof(uint64_t))
		mask = (1ull << (size * 8)) - 1;
	num &= mask;
	if (elem->specifier == 'd' || elem->specifier == 'i')
	{
		if (num & (1ull << ((size * 8) - 1)))
		{
			elem->is_negative_num = 1;
			num = (~num + 1) & mask;
		}
		if (elem->flags & Flags_Sign && !elem->is_negative_num)
			elem->sign = '+';
		else if (elem->flags & Flags_Space && !elem->is_negative_num)
			elem->sign = ' ';
		else if (elem->is_negative_num)
			elem->sign = '-';
	}
	return (num);
}

uint64_t			get_arg_int(t_format *elem, va_list *args)
{
	if (elem->specifier == 'p')
		return (va_arg(*args, size_t));
	if (elem->length == Length_None)
		return (arg_int(elem, sizeof(int), (uint64_t)va_arg(*args, int)));
	else if (elem->length == Length_H)
		return (arg_int(elem, sizeof(short), (uint64_t)va_arg(*args, int)));
	else if (elem->length == Length_HH)
		return (arg_int(elem, sizeof(char), (uint64_t)va_arg(*args, int)));
	else if (elem->length == Length_L)
		return (arg_int(elem, sizeof(long), (uint64_t)va_arg(*args, long)));
	else if (elem->length == Length_LL)
	{
		return (arg_int(elem,
				sizeof(long long),
				(uint64_t)va_arg(*args, long long)));
	}
	return (0);
}

double				get_arg_float(t_format *elem, va_list *args)
{
	double			num;

	num = va_arg(*args, double);
	if (ft_signbit(num))
	{
		elem->is_negative_num = 1;
		num = -num;
	}
	if (ft_isnan(num))
		elem->flags &= ~(Flags_Sign | Flags_Space | Flags_PaddingByZero);
	if (ft_isinf(num))
		elem->flags &= ~(Flags_PaddingByZero);
	if (elem->flags & Flags_Sign && !elem->is_negative_num)
		elem->sign = '+';
	else if (elem->flags & Flags_Space && !elem->is_negative_num)
		elem->sign = ' ';
	else if (elem->is_negative_num)
		elem->sign = '-';
	return (num);
}
