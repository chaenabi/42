/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 09:57:20 by mylee             #+#    #+#             */
/*   Updated: 2020/12/05 12:12:04 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		validate_base(char *base)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		size = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[size])
		{
			if (base[i] == base[size])
				return (0);
			size++;
		}
		i++;
	}
	return (1);
}

int		ft_exceptions(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2", 2);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	result[1000];
	int	i;

	i = 0;
	size = 0;
	if (validate_base(base))
	{
		nbr = ft_exceptions(nbr);
		while (base[size])
			size++;
		while (nbr)
		{
			result[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[result[i]]);
	}
}
