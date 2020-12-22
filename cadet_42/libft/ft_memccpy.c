#include "libft.h"

void	            *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char   *result;
	unsigned char   *uc_src;
	unsigned char   find;
	size_t          i;

	result = dest;
	uc_src = (unsigned char *)src;
	find = c;
	i = 0;
	while (i < n)
	{
		result[i] = uc_src[i];
		if (result[i] == find)
			return (dest + (i + 1));
		i++;
	}
	return (0);
}