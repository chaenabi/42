#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t  size;

    if (s == '\0')
        return (NULL);
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    size = ft_strlen(s);
    if (size <= start)
    {
        str[0] = '\0';
        return (str);
    }
    ft_strlcpy(str, s + start, len + 1);
    return (str);
}