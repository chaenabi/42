/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:57:32 by mylee             #+#    #+#             */
/*   Updated: 2021/02/10 20:19:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
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
