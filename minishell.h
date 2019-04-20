#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# define WHITESPACE " \t\r\n\a"
# define IS_QUOTE(x)(x == '"' || x == '\'')
# define IS_ALPHA(x)((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
# define IS_NUM(x)(x >= '0' && x <= '9')
# define ENV_CHAR(x)(IS_ALPHA(x) || IS_NUM(x))
# define ENV_ILLEGAL(x)(x == '=' || x == '$')

extern char **g_ms_env;
extern int (*g_builtin_func[])(char **);
extern const char *g_builtin_str[];

void ms_loop();
int ms_builtin_cd(char **args);
int ms_builtin_exit(char **args);
int ms_builtin_echo(char **args);
int ms_builtin_env(char **args);
int ms_builtin_setenv(char **args);
int ms_builtin_unsetenv(char **args);
int ms_builtin_help(char **args);

int ms_num_builtins();
void freeenv(char ***ms_env);
char *get_full_path();
char **ft_strarrdup(char **str);
int env_len(char **env);
char *ft_strchrjoin(char const *s1, char c);

int ms_execute(char **args);
int check_expansions(char **args);
char *get_envv_name(char *arg);

int locate_env_var(char *name);
char *get_env_var(char *name);
void add_env_var(char *name, char *value);
void modify_env_var(char *name, char *new_value);
void delete_env_var(char *name);

void ms_error_basic(char *message);
void ms_error_arg(char *message, char *arg);
void ms_error_envv(char *name);
void ms_unmatched_quotes(int unmatched);

int do_expansions(char ***args);
int validate_env_input(char *name, char *val);

#endif
