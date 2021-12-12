/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.seoul42.kr>          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:22:01 by mylee            #+#    #+#              */
/*   Updated: 2020/11/22 05:49:29 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);
void ft_print(int flag, char when_egde, char when_not_edge);

void rush(int x, int y)
{
	int row;
	int col;
	int edge;

	row = 1; // row starts 1
	while (row <= y)
	{
		col = 1; // column starts 1
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

void ft_print(int flag, char when_edge, char when_not_edge)
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
