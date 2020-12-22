#include "libft.h"

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;
	int				check;

	i = 0;
	check = 0;
	while (i < n)
	{
		if (check == 1 || src[i] == '\0')
		{
			dst[i] = '\0';
			check = 1;
		}
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}