/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:56:32 by mylee             #+#    #+#             */
/*   Updated: 2020/12/05 11:47:41 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r'
			|| c == '\n');
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_find_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int	result;
	int	negative;
	int	base_len;

	result = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	negative = *str == '-';
	str += (*str == '+' || *str == '-') ? 1 : 0;
	while (ft_find_char(*str, base) < base_len)
		result = result * base_len - ft_find_char(*str++, base);
	return (negative ? result : -result);
}
