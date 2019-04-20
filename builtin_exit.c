#include "minishell.h"

int ms_builtin_exit(char **args) {
	if (args[1]) {
		ft_putendl_fd("exit: Expression Syntax.", STDERR_FILENO);
		return (1);
	}
	return (0);
}
