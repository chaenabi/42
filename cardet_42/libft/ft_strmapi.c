/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:48:27 by jinbekim          #+#    #+#             */
/*   Updated: 2020/12/28 01:19:17 by jinbekim         ###   ########.fr       */
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
