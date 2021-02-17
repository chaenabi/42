/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:22:53 by mylee             #+#    #+#             */
/*   Updated: 2021/02/16 01:00:35 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_min(int a, int b)
{
	return (a < b ? a : b);
}

int						ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int						ft_abs(int a)
{
	return (a < 0 ? -a : a);
}
