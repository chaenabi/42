/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:54:22 by mylee             #+#    #+#             */
/*   Updated: 2020/11/21 22:58:55 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rush(int x, int y);

int ft_size(char *param)
{
	int i;

	i = 0;
	while(param[i++] != '\0');
	return (i-1);
}

int	ft_atoi(char *param)
{
	int n;
	int i;
	int flag;
	int size;

	size = ft_size(param);
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

	if(flag)
	{
		n = -n;
	}
	return n;
}

int	main(int argc, char *argv[])
{
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
