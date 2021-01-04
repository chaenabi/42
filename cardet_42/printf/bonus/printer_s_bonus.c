/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:23:11 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:03:36 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
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
