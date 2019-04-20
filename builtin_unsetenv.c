#include "minishell.h"

int ms_builtin_unsetenv(char **args) {
	if (args[1]) {
		if (locate_env_var(args[1]) >= 0) {
			delete_env_var(args[1]);
		}
	}
	return (1);
}
