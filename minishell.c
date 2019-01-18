#include "minishell.h"

char    **g_ms_env = NULL;

void    ms_init_env(int ac, char **av, char **environ)
{
    int size;
    int i;

    size = ft_strarrlen(environ);
    i = -1;
    ac = 0;
    av = NULL;
    g_ms_env = (char **)malloc((sizeof(char *) * size) + 1);
    while (++i < size)
        g_ms_env[i] = ft_strdup(environ[i]);
    g_ms_env[i] = NULL;
}

int     main(int ac, char **av, char **environ)
{
    ms_init_env(ac, av, environ);
    ms_loop();
    return (0);
}