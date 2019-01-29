/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:58:13 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:00:20 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*get_full_path(void)
{
	char path[PATH_MAX];

	return (getcwd(path, sizeof(path)));
}

static void		change_dir(char *path)
{
	modify_env_var("OLDPWD", get_full_path());
	chdir(path);
	modify_env_var("PWD", get_full_path());
}

int				ms_builtin_cd(char **args)
{
	char *oldpwd;

	if (!args[1])
		change_dir(get_env_var("HOME") + 5);
	else if (ft_strequ(args[1], "-"))
	{
		oldpwd = ft_strdup(get_env_var("OLDPWD") + 7);
		change_dir(oldpwd);
	}
	else
	{
		if (access(args[1], F_OK) != -1)
		{
			if (access(args[1], X_OK) != -1)
				change_dir(args[1]);
			else
				ms_error_arg("permission denied", args[1]);
		}
		else
			ms_error_arg("no such file or directory", args[1]);
	}
	return (1);
}
