/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 05:48:04 by jekim             #+#    #+#             */
/*   Updated: 2020/11/22 05:49:58 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_print(int flag, char when_egde, char when_not_edge);

void	rush(int x, int y)
{
	int row;
	int col;
	int edge;

	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			edge = col == 1 || col == x;
			if (row == 1 || row == y)
			{
				ft_print(edge, 'o', '-');
			}
			else
			{
				ft_print(edge, '|', ' ');
			}
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	ft_print(int flag, char when_edge, char when_not_edge)
{
	if (flag)
	{
		ft_putchar(when_edge);
	}
	else
	{
		ft_putchar(when_not_edge);
	}
}
