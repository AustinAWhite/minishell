/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:14:26 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:19:51 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		exec_search_path(char **args)
{
	int		i;
	char	**paths;

	i = -1;
	paths = ft_strsplit(get_env_var("PATH") + 5, ':');
	execve(args[0], args, g_ms_env);
	while (paths[++i] && paths != NULL)
		execve(ft_strjoin(ft_strjoin(paths[i], "/"), args[0]), args, g_ms_env);
	return (0);
}

static int		ms_launch(char **args)
{
	pid_t	child_pid;
	int		status;

	child_pid = fork();
	if (child_pid >= 0)
	{
		if (child_pid == 0)
		{
			if (exec_search_path(args) == 0)
				ms_error_arg("command not found", args[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			return (1);
		}
	}
	else
	{
		ms_error_basic("fork failed: resource temporarily unavailable");
		return (0);
	}
	return (1);
}

int				ms_execute(char **args)
{
	int i;
	int bnum;

	i = -1;
	bnum = ms_num_builtins();
	if (args[0] == NULL)
		return (1);
	while (++i < bnum)
		if (ft_strcmp(args[0], g_builtin_str[i]) == 0)
			return ((*g_builtin_func[i])(args));
	return (ms_launch(args));
}
