/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:28:03 by mylee             #+#    #+#             */
/*   Updated: 2020/11/25 18:28:21 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int index;
	int src_index;

	index = 0;
	while (dest[index] != '\0')
		index++;
	src_index = 0;
	while (src[src_index] != '\0')
	{
		dest[index + src_index] = src[src_index];
		src_index++;
	}
	dest[index + src_index] = '\0';
	return (dest);
}
