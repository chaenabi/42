/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 05:18:35 by clim              #+#    #+#             */
/*   Updated: 2020/11/22 05:18:37 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rush(int x, int y);

int		main(void)
{
	rush(5, 3);
	printf("\n");
	rush(5, 1);
	printf("\n");
	rush(1, 1);
	printf("\n");
	rush(1, 5);
	printf("\n");
	rush(4, 4);
	printf("\n");
	return (0);
}