#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t		s1_len;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len && ft_strchr(set, s1[s1_len]))
		s1_len--;
	newstring = ft_substr((char*)s1, 0, s1_len + 1);
	return (newstring);
}