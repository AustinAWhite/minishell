#include "minishell.h"

int     check_expansions(char **args)
{
    int i;
    int ret;

    i = -1;
    while (args[++i])
    {
        if (ft_strchr(args[i], '$'))
            if ((ret = locate_env_var(get_envv_name(
                    ft_strchr(args[i], '$') + 1))) == -1)
            {
                ms_error_envv(ft_strchr(args[i], '$') + 1);
                return (0);
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
    while (IS_ALPHA(arg[len]))
        len++;
    name = ft_strnew(len);
    while (++j < len)
        name[j] = arg[i++];
    name[j] = '\0';
    return (name);
}