#include "minishell.h"

int     ms_num_builtins()
{
    int num;

    num = 0;
    while (g_builtin_str[num])
        num++;
    return (num);
}

void    freeenv(char ***ms_env)
{
    int i;
    char **tmp;

    i = -1;
    tmp = *ms_env;
    while (tmp[++i])
        free(tmp[i]);
    free(tmp);
}