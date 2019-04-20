#include "minishell.h"

int ms_builtin_help(char **args) {
	int fd;
	char *filename;
	char *line;

	(void)args;
	filename = "resources/help.txt";
	if ((fd = open(filename, O_RDONLY)) < 0) {
		ms_error_arg("file not found", filename);
	}
	if (fd > 0) {
		while (get_next_line(fd, &line)) {
			ft_putendl(line);
		}
	}
	return (1);
}
