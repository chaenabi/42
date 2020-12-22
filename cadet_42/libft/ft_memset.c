#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*result;
	unsigned char	uc_src;
	size_t			i;

	result = (unsigned char *)s;
	uc_src = (unsigned char)c;
	i = 0;
	while (i++ < n)
		*result++ = uc_src;
	return (s);
}