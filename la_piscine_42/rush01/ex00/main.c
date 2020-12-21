/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:19:51 by mylee             #+#    #+#             */
/*   Updated: 2020/11/28 12:57:59 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
//#include "init.h"

int	 validate_input(char *str);
void init(char *input);

extern char map[6][6];

int	main(int argc, char *argv[])
{
	if (argc == 2 && validate_input(argv[1]))
	{
		init(argv[1]);
	}
	else 
	{
		write(1, "Error", 5);
	}

	int x = 0;
	int y = 0;
	while (y < 7)
	{
		while (x < 7)
		{
			printf("%c ", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}


	write(1, "\n", 1);
	return (0);
}
