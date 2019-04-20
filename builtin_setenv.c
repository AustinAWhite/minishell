#include "minishell.h"

int ms_builtin_setenv(char **args)
{
	if (args[1] == NULL)
		ms_builtin_env(args);
	else if (args[2] == NULL)
	{
		ft_putendl_fd("minishell: no env value supplied.", STDERR_FILENO);
		return (1);
	}
	else
	{
		if (validate_env_input(args[1], args[2]) > 0)
			return (1);
		if (locate_env_var(args[1]) >= 0)
			modify_env_var(args[1], args[2]);
		else
			add_env_var(args[1], args[2]);
	}
	return (1);
}
