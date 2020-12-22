/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mylee <mylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:18:24 by mylee             #+#    #+#             */
/*   Updated: 2020/12/23 00:39:50 by mylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return ((65 <= c) && (90 >= c));
}

int			ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
