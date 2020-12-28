/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:14:03 by mylee             #+#    #+#             */
/*   Updated: 2020/12/28 11:08:16 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace(char c)
{
	return ((c == 32) || (c >= 9 && c <= 13));
}

int				ft_atoi(const char *nptr)
{
	int			flag;
	int			result;
	int			i;

	i = 0;
	flag = 1;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		flag = -1;
	while (nptr[i] == '-' || nptr[i] == '+')
		i++;
	result = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (result * flag > 2147483647)
			return (-1);
		else if (result * flag < -2147483648)
			return (0);
		else
			result = 10 * result + (nptr[i++] - '0');
	}
	if (flag == -1)
		result = -result;
	return (result);
}
