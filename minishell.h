/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:34:20 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:36:04 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <sys/stat.h>
# include <stdio.h>
# define WHITESPACE " \t\r\n\a"
# define IS_QUOTE(x)(x == '"' || x == '\'')

extern char **g_ms_env;
extern char *g_path_backup;

int			ms_builtin_exit(char **args);
int			ms_builtin_cd(char **args);
int			ms_builtin_echo(char **args);
int			ms_builtin_env(char **args);
int			ms_builtin_setenv(char **args);
int			ms_builtin_unsetenv(char **args);

static int	(*g_builtin_func[])(char **) = {
	&ms_builtin_cd,
	&ms_builtin_exit,
	&ms_builtin_echo,
	&ms_builtin_env,
	&ms_builtin_setenv,
	&ms_builtin_unsetenv
};

static const char *g_builtin_str[] = {
	"cd",
	"exit",
	"echo",
	"env",
	"setenv",
	"unsetenv",
	NULL
};

void		ms_loop();

int			ms_num_builtins();
void		freeenv(char ***ms_env);
char		*get_full_path();

int			ms_execute(char **args);

int			locate_env_var(char *name);
char		*get_env_var(char *name);
void		add_env_var(char *name, char *value);
void		modify_env_var(char *name, char *new_value);
void		delete_env_var(char *name);

#endif
