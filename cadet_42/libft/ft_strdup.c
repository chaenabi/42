#include "libft.h"

char        *ft_strdup(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(s) + 1);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}