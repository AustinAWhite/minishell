#include "libft.h"

int ft_strdelims(char *str, char *delims)
{
    int i;
    int j;

    i = -1;
    while (str[++i])
    {
        j = -1;
        while (delims[++j])
            if (str[i] == delims[j])
                return (i);
    }
    return (-1);
}