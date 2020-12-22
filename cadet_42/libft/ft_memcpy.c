#include "libft.h"

void                *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char   *result;
	unsigned char   *uc_src;
	size_t          i;

	if (!dest && !src)
		return (0);
	result = dest;
	uc_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*result++ = *uc_src++;
	return (result);
}
