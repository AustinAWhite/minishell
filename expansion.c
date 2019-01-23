#include "minishell.h"

int     check_expansions(char **args)
{
    int i;
    char *name;

    i = 0;
    while (args[++i])
    {
        if (ft_strcmp(args[i], "$") == 0)
            return (1);
        if (ft_strchr(args[i], '$'))
        {
            name = get_envv_name(ft_strchr(args[i], '$') + 1);
            if (name == NULL || locate_env_var(name) == -1)
            {
                if (name == NULL)
                    ft_putendl_fd("Illegal variable name", STDERR_FILENO);
                else
                    ms_error_envv(ft_strchr(args[i], '$') + 1);
                return (0);
            }
        }
    }
    return (1);
}

char    *get_envv_name(char *arg)
{
    int i;
    int j;
    int len;
    char *name;

    i = 0;
    j = -1;
	len = 0;
    if (!IS_ALPHA(arg[0]))
        return (NULL);
    while (IS_ALPHA(arg[len]))
        len++;
    name = ft_strnew(len);
    while (++j < len)
        name[j] = arg[i++];
    name[j] = '\0';
    return (name);
}