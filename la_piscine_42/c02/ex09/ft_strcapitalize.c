/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:08:11 by mylee             #+#    #+#             */
/*   Updated: 2020/11/26 14:03:20 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	int		sp;

	i = 0;
	while (str[i] != '\0')
	{
		sp = 1;
		if (i == 0)
			c = '+';
		else
			c = str[i - 1];
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			sp = 0;
		if (c >= '0' && c <= '9')
			sp = 0;
		if (sp == 1 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		if (sp == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
