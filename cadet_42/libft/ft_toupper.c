/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:15:13 by mylee             #+#    #+#             */
/*   Updated: 2020/12/23 00:42:21 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return ((97 <= c) && (122 >= c));
}

int			ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
