/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:40:04 by mylee             #+#    #+#             */
/*   Updated: 2020/11/23 20:42:23 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(char hund, char ten, char one)
{
	write(1, &hund, 1);
	write(1, &ten, 1);
	write(1, &one, 1);
}

void	ft_print_comb(void)
{
	char arr[5];

	arr[0] = '0';
	arr[3] = ',';
	arr[4] = ' ';
	while (arr[0] <= '7')
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= '8')
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= '9')
			{
				ft_print_number(arr[0], arr[1], arr[2]);
				if (!(arr[0] == '7' && arr[1] == '8' && arr[2] == '9'))
				{
					write(1, &arr[3], 1);
					write(1, &arr[4], 1);
				}
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}
