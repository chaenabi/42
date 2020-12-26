/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:58:53 by mylee             #+#    #+#             */
/*   Updated: 2020/12/22 22:58:54 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				check;

	i = 0;
	check = 0;
	while (i < n)
	{
		if (check == 1 || src[i] == '\0')
		{
			dest[i] = '\0';
			check = 1;
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
