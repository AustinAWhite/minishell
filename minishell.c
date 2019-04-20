#include "minishell.h"

char **g_ms_env = NULL;

int	(*g_builtin_func[])(char **) = {
	&ms_builtin_cd,
	&ms_builtin_exit,
	&ms_builtin_echo,
	&ms_builtin_env,
	&ms_builtin_setenv,
	&ms_builtin_unsetenv,
	&ms_builtin_help
};

const char *g_builtin_str[] = {
	"cd",
	"exit",
	"echo",
	"env",
	"setenv",
	"unsetenv",
	"help",
	NULL
};

int env_len(char **env) {
	int i;

	i = 0;
	while (env[i]) {
		i++;
	}
	return (i);
}

void ms_init_env(char **environ) {
	int i;
	int size = env_len(environ);
	
	g_ms_env = (char **)malloc((sizeof(char *) * size) + 1);
	for (i = 0; i < size; i++) {
		g_ms_env[i] = ft_strdup(environ[i]);
	}
	g_ms_env[i] = NULL;
}

int main(int ac, char **av, char **environ) {
	(void)ac;
	(void)av;
	ms_init_env(environ);
	ms_loop();
	return (0);
}
