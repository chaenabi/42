/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:38:13 by mylee             #+#    #+#             */
/*   Updated: 2020/12/06 23:01:31 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void				ft_strcpy(char *dst, char *src)
{
	int				i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*array;
	int				i;

	array = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = (char*)malloc(array[i].size + 1);
		array[i].copy = (char*)malloc(array[i].size + 1);
		ft_strcpy(array[i].str, av[i]);
		ft_strcpy(array[i].copy, av[i]);
		i++;
	}
	array[i].str = 0;
	return (array);
}
