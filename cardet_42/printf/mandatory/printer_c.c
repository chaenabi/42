/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/15 20:12:16 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void		padding(t_printf *p, t_format *e, int side)
{
	int			ch;
	int			len;

	if (side == Side_Head && (e->flags & Flags_LeftJustify))
		return ;
	if (side == Side_Tail && !(e->flags & Flags_LeftJustify))
		return ;
	if (side == Side_Head && e->flags & Flags_PaddingByZero)
		ch = '0';
	else
		ch = ' ';
	len = e->width - 1;
	while (len-- > 0)
		ft_putchar_pf(p, ch);
}

void			print_c(t_printf *p, t_format *e, va_list *args)
{
	padding(p, e, Side_Head);
	ft_putchar_pf(p, e->specifier == 'c' ? va_arg(*args, int) : '%');
	padding(p, e, Side_Tail);
}
