/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 23:29:15 by mylee             #+#    #+#             */
/*   Updated: 2020/11/29 23:33:56 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int num;

	if (nb < 0)
		return (0);
	i = 2;
	num = 1;
	while (i <= nb)
	{
		num *= i;
		i++;
	}
	return (num);
}
