/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_memory_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:16:00 by smun              #+#    #+#             */
/*   Updated: 2021/01/02 22:02:44 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int				bigint_alloc(t_bigint *b, int blocks, int fill_blocks_as_zero)
{
	int			blockmemsize;

	blockmemsize = (1 + blocks) * sizeof(unsigned int);
	if ((b->block = malloc(sizeof(t_bigint) + blockmemsize)))
	{
		b->blocksmax = blocks;
		b->blockcnt = 0;
		b->negative = 0;
		if (fill_blocks_as_zero)
			ft_bzero(b->block, blockmemsize);
		return (TRUE);
	}
	return (FALSE);
}

void			bigint_free(uint32_t *pb, uint32_t *ps)
{
	if (pb)
		free(pb);
	if (ps)
		free(ps);
}

int				bigint_ensure(t_bigint *bigint, int needs)
{
	uint32_t	blockcnt;
	uint32_t	*blocks;

	if (bigint->blocksmax < needs)
	{
		blocks = bigint->block;
		blockcnt = bigint->blockcnt;
		if (bigint_alloc(bigint, needs, TRUE))
		{
			ft_memcpy(bigint->block, blocks, blockcnt * sizeof(uint32_t));
			free(blocks);
			return (TRUE);
		}
		free(blocks);
		return (FALSE);
	}
	return (TRUE);
}

void			bigint_replace(t_bigint *dest, t_bigint *src)
{
	if (dest == src)
		return ;
	dest->negative = src->negative;
	dest->blocksmax = src->blocksmax;
	dest->blockcnt = src->blockcnt;
	free(dest->block);
	dest->block = src->block;
}
