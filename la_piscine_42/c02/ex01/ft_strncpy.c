/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:47:13 by mylee             #+#    #+#             */
/*   Updated: 2020/11/25 15:31:22 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
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
