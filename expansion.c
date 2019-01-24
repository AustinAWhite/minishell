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
                    ms_error_envv(get_envv_name(ft_strchr(args[i], '$') + 1));
                return (1);
            }
        }
    }
    return (0);
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
    if (!ENV_CHAR(arg[0]) || !arg)
        return (NULL);
    while (ENV_CHAR(arg[len]))
        len++;
    name = ft_strnew(len);
    while (++j < len)
        name[j] = arg[i++];
    name[j] = '\0';
    return (name);
}

void    replace_home_expansion(char **arg)
{
    char *newarg;
    char *home;

    newarg = NULL;
    home = get_env_var("HOME") + 5;
    newarg = ft_strjoin(home, *arg + 1);
    free(*arg);
    *arg = newarg;
}

void    replace_expansion(char **arg)
{
    char    *newarg;
    char    *envval;
    char    *front;
    char    *back;
    int     namelen;

    namelen = ft_strlen(get_envv_name(ft_strchr(*arg, '$') + 1));
    envval = get_env_var(ft_strchr(*arg, '$') + 1) + namelen + 1;
    front = ft_strsub(*arg, 0, ft_strlen(*arg) - ft_strlen(ft_strchr(*arg, '$')));
    back = ft_strsub(*arg, ft_strlen(front) + namelen + 1, ft_strlen(*arg));
    newarg = ft_strjoin(ft_strjoin(front, envval), back);
    free(*arg);
    *arg = newarg;
}

int    do_expansions(char ***args)
{
    int i;
    char **tmp;

    i = 0;
    tmp = *args;
    while (tmp[++i])
    {
        if (tmp[i][0] == '~')
        {
            if (tmp[i][1] == '/' || tmp[i][1] == '\0')
                replace_home_expansion(&tmp[i]);
            else
            {
                ft_putstr_fd("Unknown user: ", STDERR_FILENO);
                ft_putendl_fd(tmp[i] + 1, STDERR_FILENO);
                return (1);
            }
        }
        if (ft_strchr(tmp[i], '$'))
            replace_expansion(&tmp[i]);
    }
    return (0);
}