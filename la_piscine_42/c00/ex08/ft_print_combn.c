/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:14:28 by mylee             #+#    #+#             */
/*   Updated: 2020/11/22 22:15:23 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print(int n, int *nums)
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = nums[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (!(nums[0] == 10 - n && nums[n - 1] == 9))
	{
		c = ',';
		write(1, &c, 1);
		c = ' ';
		write(1, &c, 1);
	}
}

void		ft_combi(int n, int m, int *picked)
{
	int		i;

	if (n == m)
	{
		ft_print(n, picked);
	}
	else
	{
		if (m == 0)
			i = 0;
		else
			i = picked[m - 1] + 1;
		while (i <= 9)
		{
			picked[m] = i;
			ft_combi(n, m + 1, picked);
			i++;
		}
	}
}

void		ft_print_combn(int n)
{
	int		picked[10];

	ft_combi(n, 0, picked);
}
