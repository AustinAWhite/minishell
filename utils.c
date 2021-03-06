#include "minishell.h"

int ms_num_builtins(void) {
	int num;

	num = 0;
	while (g_builtin_str[num]) {
		num++;
	}
	return (num);
}

void freeenv(char ***ms_env) {
	int i;
	char **tmp;

	i = -1;
	tmp = *ms_env;
	while (tmp[++i]) {
		free(tmp[i]);
	}
	free(tmp);
}

char **ft_strarrdup(char **str) {
	int i;
	int size;
	char **new;

	i = -1;
	size = env_len(str);
	new = (char **)malloc((sizeof(char *) * size) + 1);
	while (++i < size) {
		new[i] = ft_strdup(str[i]);
	}
	new[i] = NULL;
	return (new);
}

char *ft_strchrjoin(char const *s1, char c) {
	char *str;
	int i;

	i = -1;
	if (!s1 || !c) {
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(s1) + 1));
	while (s1[++i]) {
		str[i] = s1[i];
	}
	str[i++] = c;
	str[i] = '\0';
	return (str);
}
