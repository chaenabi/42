#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    unsigned int    s1_len;
    unsigned int    s2_len;
    unsigned int    i;
    unsigned int    j;

    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    if (!(result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
        return (NULL);
    while (i < s1_len)
    {
        result[i] = s1[i];
    }
    while (j < s2_len)
    {
        result[i++] = s2[j];
    }
    result[i] = '\0';
    return (result);
}