/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 20:55:10 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:03:43 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
