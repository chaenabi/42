#include "libft.h"

void                ft_bzero(void *s, size_t n)
{
	unsigned char   *dst;
	size_t          i;

	dst = s;
	i = 0;
	while (i++ < n)
		*dst++ = 0;
}
