#include "minishell.h"

char    *find_next_expansions(char *arg)
{
    int i;
    int found;
    char *next;

    i = -1;
    found = 0; 
    next = arg;
    while (next[++i])
    {
        if (next[i] == '$')
            found++;
        if (found == 2)
            break;
    }
    return (next + i);
}

int     check_expansions(char **args)
{
    int i;
    char **cut;
    char *name;

    i = 0;
    cut = ft_strarrdup(args);
    while (cut[++i])
    {
        if (ft_strcmp(cut[i], "$") == 0)
            return (1);
        while (ft_strchr(cut[i], '$'))
        {
            name = get_envv_name(ft_strchr(cut[i], '$') + 1);
            if (name == NULL || locate_env_var(name) == -1)
            {
                if (name == NULL)
                    ft_putendl_fd("Illegal variable name", STDERR_FILENO);
                else
                    ms_error_envv(get_envv_name(ft_strchr(cut[i], '$') + 1));
                return (1);
            }
            cut[i] = find_next_expansions(cut[i]);
        }
    }
    return (0);
}

void    expand_home(char **arg)
{
    char *newarg;
    char *home;

    newarg = NULL;
    home = get_env_var("HOME") + 5;
    newarg = ft_strjoin(home, *arg + 1);
    free(*arg);
    *arg = newarg;
}

void    expand_envv(char **arg)
{
    char    *newarg;
    char    *envval;
    char    *front;
    char    *back;
    int     namelen;

    namelen = ft_strlen(get_envv_name(ft_strchr(*arg, '$') + 1));
    envval = get_env_var(get_envv_name(ft_strchr(*arg, '$') + 1)) + namelen + 1;
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
                expand_home(&tmp[i]);
            else
            {
                ft_putstr_fd("Unknown user: ", STDERR_FILENO);
                ft_putendl_fd(tmp[i] + 1, STDERR_FILENO);
                return (1);
            }
        }
        while (ft_strchr(tmp[i], '$'))
            expand_envv(&tmp[i]);
    }
    return (0);
}