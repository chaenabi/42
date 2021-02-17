/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:44:31 by mylee             #+#    #+#             */
/*   Updated: 2021/02/15 22:53:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void		padding(t_printf *p, t_format *e, int side, int len)
{
	char		ch;

	if (side == Side_Head && (e->flags & Flags_LeftJustify))
		return ;
	if (side == Side_Tail && !(e->flags & Flags_LeftJustify))
		return ;
	len = e->width - len;
	if (e->flags & Flags_PaddingByZero)
		ch = '0';
	else
		ch = ' ';
	ft_putchar_len_pf(p, ch, len);
}

void			print_s(t_printf *p, t_format *e, va_list *args)
{
	char		*s;
	int			len;

	s = va_arg(*args, char*);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (e->precision_mode && e->precision >= 0)
		len = ft_min(e->precision, len);
	padding(p, e, Side_Head, len);
	ft_putstr_len_pf(p, s, len);
	padding(p, e, Side_Tail, len);
}
