#include "minishell.h"

char        *get_full_path()
{
    char path[PATH_MAX];

    return (getcwd(path, sizeof(path)));
}

static void        change_dir(char *path)
{
    modify_env_var("OLDPWD", get_full_path());
    chdir(path);
    modify_env_var("PWD", get_full_path());
}

int         ms_builtin_cd(char **args)
{
    if (!args[1])
        ft_putendl_fd("minishell: exptected directory path", STDERR_FILENO);
    else
    {
        if (access(args[1], F_OK) != -1)
        {
            if (access(args[1], X_OK) != -1)
                change_dir(args[1]);
            else
            {
                ft_putstr_fd("minishell: permission denied: ", STDERR_FILENO);
                ft_putendl_fd(args[1], STDERR_FILENO);
            }
        }
        else
        {
            ft_putstr_fd("minishell: no such file or directory: ", STDERR_FILENO);
            ft_putendl_fd(args[1], STDERR_FILENO);
        }
    }
    return (1);
}