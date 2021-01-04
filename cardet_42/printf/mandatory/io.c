/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:46:36 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 21:45:00 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void				ft_putchar_pf(t_printf *p, int c)
{
	write(p->fd, &c, 1);
	p->len += 1;
}

void				ft_putchar_len_pf(t_printf *p, int c, int len)
{
	while (len-- > 0)
		ft_putchar_pf(p, c);
}

void				ft_putstr_pf(t_printf *p, const char *c)
{
	size_t			len;

	if (c == NULL)
		return ;
	len = ft_strlen(c);
	write(p->fd, c, len);
	p->len += len;
}

void				ft_putstr_len_pf(t_printf *p, const char *c, int len)
{
	if (c == NULL)
		return ;
	write(p->fd, c, len);
	p->len += len;
}
