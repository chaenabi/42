/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:27:44 by mylee             #+#    #+#             */
/*   Updated: 2020/11/25 18:27:48 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (index < n && s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] > s2[index])
			return (1);
		else if (s1[index] < s2[index])
			return (-1);
		index++;
	}
	if (index == n)
		return (0);
	if (s1[index] == '\0' && s2[index] == '\0')
		return (0);
	if (s1[index] == '\0')
		return (-1);
	return (1);
}
