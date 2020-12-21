/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 09:45:04 by mylee             #+#    #+#             */
/*   Updated: 2020/11/30 16:33:20 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int cnt;
	int flag;

	cnt = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\v'
		|| *str == '\r' || *str == '\n' || *str == '-' || *str == '+')
	{
		if (*str == '-')
			++cnt;
		str++;
	}
	if (cnt % 2 == 1)
		flag = 1;
	cnt = 0;
	while (*str >= '0' && *str <= '9')
	{
		cnt = 10 * cnt + (*str - 48);
		str++;
	}
	if (flag)
		cnt = -cnt;
	return (cnt);
}
