/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:44:53 by mylee             #+#    #+#             */
/*   Updated: 2020/11/28 12:59:07 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//extern char map[6][6];

char map[6][6];

int	is_space(char c)
{
	return (c == ' ');
}

int is_range(char c)
{
	return (c >= '1' && c <= '4');
}

int	validate_input(char *str)
{
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if(!is_space(str[i]))
			cnt++;
		i++;
	}
	i = 0;	
	while(str[i] != '\0')
	{
		if(!is_space(str[i]))
		{
			if(!is_range(str[i]))
			{	
				return (0); // 검증 실패된 입력값. init 수행하지 않음.
			}
		}
		i++;
	}
	return (1); // 검증된 입력값이므로 1 리턴
}

void	init(char *str)
{
	int x;
	int	y;
	// int arr[6][6];

	x = 0;
	y = 0;
	while (x++ < 7)
	{
		while (y++ < 7)
		{
			map[y][x] = '0';
		}
	} // 처음에는 0 으로 모두 초기화.

	x = 1;
	while (x < 5)
	{
		if (!is_space(*str))
			map[0][x] = *str;
		x++;
		str++;
	}
	x = 1;
	while (x < 5)
	{
		if (!is_space(*str))
			map[5][x] = *str;
		x++;
		str++;
	}
	y = 1;
	while (y < 5)
	{
		if (!is_space(*str))
			map[y][0] = *str;
		y++;
		str++;
	}
	y = 1;
	while (y < 5)
	{
		if (!is_space(*str))
			map[y][5] = *str;
		y++;
		str++;
	}


}
