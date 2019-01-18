#include "minishell.h"

static void print_arg(char *arg)
{
    int i;

    i = -1;
    if (arg[0] == '$' || arg[0] == '~')
    {
        ft_putstr((get_env_var(arg + 1) + ft_strlen(arg)));
        return ;
    }
    while (arg[++i])
    {
        if (arg[i] == '\\')
            if (IS_QUOTE(arg[i + 1]))
            {
                ft_putchar(arg[i + 1]);
                continue;
            }
        if (!IS_QUOTE(arg[i]))
            ft_putchar(arg[i]);
    }
}

int         ms_builtin_echo(char **args)
{
    int i;
    int n_flag;

    i = 0;
    n_flag = 0;
    if (!args[1])
    {
        ft_putchar('\n');
        return (1);
    }
    if (args[1][0] == '-' && args[1][1] == 'n' && args[1][2] == '\0')
    {
        n_flag = 1;
        i++;
    }
    while (args[++i])
    {
        print_arg(args[i]);
        if (args[i + 1])
            ft_putchar(' ');
    }
    if (!n_flag)
        ft_putchar('\n');
    return (1);
}