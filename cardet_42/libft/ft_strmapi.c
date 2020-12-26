#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t  s_len;
    size_t  i;
    char    *result;

    i = 0;
    if (*s == '\0')
        return (NULL);
    s_len = ft_strlen(s);
    if (!(result = (char *)malloc(sizeof(char) * (s_len + 1))))
        return (NULL);
    while (i < s_len)
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}