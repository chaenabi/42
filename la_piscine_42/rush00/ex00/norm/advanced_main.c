/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 07:20:42 by jekim             #+#    #+#             */
/*   Updated: 2020/11/22 08:22:14 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rush(int x, int y);

int		ft_atoi(char *param)
{
	int n;
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (param[0] == '-')
	{
		i++;
		flag++;
	}
	n = 0;
	while (param[i] >= '0' && param[i] <= '9')
	{
		n = 10 * n + (param[i++] - '0');
	}
	if (flag)
	{
		return (-1);
	}
	return (n);
}

int		main(int argc, char *argv[])
{
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
