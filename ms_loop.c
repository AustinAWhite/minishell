#include "minishell.h"

static char    *ms_read_line()
{
    char *line;

    line = NULL;
    get_next_line(STDIN_FILENO, &line);
    return (line);
}

static char    **ms_split_line(char *line)
{
    char **split_line;
    
    split_line = ft_strtok_mod(line, WHITESPACE);
    return (split_line);
}

void    ms_loop()
{
    char    *line;
    char    **args;
    int     status;

    status = 1;
    while (status)
    {
        ft_putstr("$> ");
        line = ms_read_line();
        args = ms_split_line(line);
        status = ms_execute(args);
        free(args);
        free(line);
    }
}