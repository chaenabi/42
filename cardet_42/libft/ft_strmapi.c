/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 01:12:45 by mylee             #+#    #+#             */
/*   Updated: 2020/12/31 01:12:48 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ans;

	i = 0;
	if (!(ans = malloc(ft_strlen(s) + 1)))
		return (0);
	while (*s)
	{
		ans[i] = f(i, *s);
		s++;
		i++;
	}
	ans[i] = 0;
	return (ans);
}
