/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 05:47:34 by jekim             #+#    #+#             */
/*   Updated: 2020/11/22 05:47:39 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_print(int row, int col, int col_end, int row_end);

void	rush(int x, int y)
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

void	ft_print(int row, int col, int col_end, int row_end)
{
	if (row == 1)
	{
		if (col == 1)
			ft_putchar('/');
		else if (col == col_end)
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
	else if (row == row_end)
	{
		if (col == 1)
			ft_putchar('\\');
		else if (col == col_end)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
	else
	{
		if (col == 1 || col == col_end)
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}
