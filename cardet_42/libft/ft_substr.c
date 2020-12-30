/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 01:13:11 by mylee             #+#    #+#             */
/*   Updated: 2020/12/31 01:13:15 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!(arr = malloc(len + 1)))
		return (0);
	while ((i < len) && s[i + start])
	{
		arr[i] = s[i + start];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
