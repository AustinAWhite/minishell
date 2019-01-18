#include "libft.h"

int     ft_strarrlen(char **str)
{
    int len;

    len = -1;
    while (str[++len])
        continue;
    return (len);
}