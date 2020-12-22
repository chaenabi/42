#include "libft.h"

int                 ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t          i;
	unsigned char   *c1;
	unsigned char   *c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (c1[i] != c2[i] || c1[i] == 0 || c2[i] == 0)
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
