#include "libft.h"

size_t	ft_strlcpy(char *dest,const char *src, size_t size)
{
	size_t			index;
	size_t			int_size;

	index = 0;
	int_size = size;
	while (index < int_size - 1 && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	while (src[index])
		index++;
	return (index);
}