#include "minishell.h"

int ms_builtin_env(char **args) {
	int i;

	i = -1;
	(void)args;
	while (g_ms_env[++i]) {
		ft_putendl(g_ms_env[i]);
	}
	return (1);
}
