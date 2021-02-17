/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = ft_vprintf(STDOUT_FILENO, format, &args);
	va_end(args);
	return (ret);
}

static void		parse_formats(t_printf *p, t_format *e)
{
	ft_bzero(e, sizeof(t_format));
	parse_flags(p, e);
	parse_width(p, e);
	parse_precision(p, e);
	parse_length(p, e);
	parse_specifier(p, e);
	if ((e->flags & Flags_PaddingByZero) && (e->flags & Flags_LeftJustify))
		e->flags &= ~Flags_PaddingByZero;
	if (e->flags & Flags_Sign)
		e->flags &= ~Flags_Space;
	if (e->precision_mode && ft_strchr("diuopxX", e->specifier))
		e->flags &= ~Flags_PaddingByZero;
}

static void		init_printf(t_printf *p, int fd, const char *f, va_list *a)
{
	p->fd = fd;
	p->format = f;
	p->args = a;
	p->len = 0;
}

/*
** 'printf' to specified the file descriptor with va_list.
*/

int				ft_vprintf(int fd, const char *format, va_list *args)
{
	t_printf	prtf;
	t_format	elem;

	init_printf(&prtf, fd, format, args);
	while (*(prtf.format))
	{
		if (*(prtf.format) == '%')
		{
			prtf.format++;
			parse_formats(&prtf, &elem);
			if (elem.specifier == 'n')
				*va_arg(*args, int*) = prtf.len;
			else if (ft_strchr("c%", elem.specifier))
				print_c(&prtf, &elem, args);
			else if (ft_strchr("pdiuopxX", elem.specifier))
				print_pdiuopx(&prtf, &elem, args);
			else if (ft_strchr("s", elem.specifier))
				print_s(&prtf, &elem, args);
			else if (ft_strchr("fgeFGE", elem.specifier))
				print_fge(&prtf, &elem, args);
		}
		else
			ft_putchar_pf(&prtf, *(prtf.format++));
	}
	return ((int)prtf.len);
}
