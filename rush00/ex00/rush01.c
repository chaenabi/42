/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.seoul42.kr>          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:55:53 by mylee            #+#    #+#              */
/*   Updated: 2020/11/21 11:36:11 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);
void ft_print(int row, int col, int col_end, int row_end);

void rush(int x, int y)
{
	int row;
	int col;

	row = 1;
	while (row < y || row == y)
	{
		col = 1;
		while (col <= x)
		{
			ft_print(row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void ft_print(int row, int col, int col_end, int row_end)
{
	if (row == 1)
	{
		if (col == 1)
		{
			ft_putchar('/');
		}
		else if (col == col_end)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
	}
	else if (row == row_end)
	{
		if (col == 1)
			ft_putchar('\\');
		else if (col == col_end)
			ft_putchar('/');
		else ft_putchar('*');
	}
	else
	{
		if (col == 1 || col == col_end)
		{
			ft_putchar('*');
		}
		else
		{
			ft_putchar(' ');
		}
	}
}
