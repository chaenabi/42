/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 00:32:08 by mylee             #+#    #+#             */
/*   Updated: 2020/12/06 14:29:58 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define TEN 10

void	ft_init(int *col);
int		ft_ten_queens_puzzle(void);
void	ft_queen(int col[], int row);
int		ft_is_possible(int col[], int row);
int		ft_abs(int number);
int		g_count;

void		ft_init(int *col)
{
	int i;

	i = 0;
	while (col[i] != 0)
	{
		col[i] = 0;
		col++;
	}
}

int			ft_ten_queens_puzzle(void)
{
	int		i;
	int		*col;

	i = 0;
	g_count = 0;
	while (i < TEN)
	{
		*col = (int *)malloc(sizeof(int) * (TEN + 1));

		col[0] = i;
		ft_queen(col, 0);
		i++;
	}
	return (g_count);
}

void		ft_queen(int col[], int row)
{
	int		i;
	char	print;

	if (row == TEN)
	{
		i = 0;
		while (col[i])
		{
			print = col[i] + 48;
			write(1, &print, 1);
			i++;
		}
		g_count++;
	}
	else
	{
		i = 0;
		while (i < TEN)
		{
			col[row + 1] = i + 1;
			if (ft_is_possible(col, row + 1))
				ft_queen(col, row + 1);
			i++;
		}
	}
}

int			ft_is_possible(int col[], int row)
{
	int		i;

	i = 0;
	while (i < row)
	{
		if (col[i] == col[row])
			return (0);
		if (ft_abs(i - row) == ft_abs(col[i] - col[row]))
			return (0);
	}
	return (1);
}

int			ft_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

int			main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
