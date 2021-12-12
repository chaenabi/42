/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 05:43:44 by jekim             #+#    #+#             */
/*   Updated: 2020/11/22 05:44:28 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c);
void	ft_print(int row, int col, int col_end, int row_end);

void	rush(int x, int y)
{
	int row;
	int col;

	row = 1;
	while (row <= y)
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

void	ft_print(int row, int col, int col_end, int row_end)
{
	if (row == 1)
	{
		if (col == 1 || col == col_end)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (row == row_end)
	{
		if (col == 1 || col == col_end)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (col == 1 || col == col_end)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}
