/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:20:14 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:20:22 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_ms_env = NULL;
char	*g_path_backup = NULL;

void	ms_init_env(int ac, char **av, char **environ)
{
	int size;
	int i;

	size = ft_strarrlen(environ);
	i = -1;
	ac = 0;
	av = NULL;
	g_ms_env = (char **)malloc((sizeof(char *) * size) + 1);
	while (++i < size)
		g_ms_env[i] = ft_strdup(environ[i]);
	g_ms_env[i] = NULL;
	g_path_backup = ft_strdup(get_env_var("PATH"));
}

int		main(int ac, char **av, char **environ)
{
	ms_init_env(ac, av, environ);
	ms_loop();
	return (0);
}
