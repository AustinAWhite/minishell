/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manip_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 00:17:52 by awhite            #+#    #+#             */
/*   Updated: 2019/01/26 00:18:05 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_var(char *name, char *value)
{
	int		i;
	char	**new_ms_env;
	int		size;

	i = -1;
	size = env_len(g_ms_env) + 1;
	new_ms_env = malloc((sizeof(char *) * size) + 1);
	while (++i < size - 2)
		new_ms_env[i] = ft_strdup(g_ms_env[i]);
	new_ms_env[i++] = ft_strjoin(ft_strjoin(name, "="), value);
	new_ms_env[i] = ft_strdup(g_ms_env[i - 1]);
	new_ms_env[++i] = NULL;
	freeenv(&g_ms_env);
	g_ms_env = new_ms_env;
}

void	modify_env_var(char *name, char *new_value)
{
	int i;

	if ((i = locate_env_var(name)) != -1)
	{
		ft_memset(g_ms_env[i], '\0', ft_strlen(g_ms_env[i]));
		free(g_ms_env[i]);
		g_ms_env[i] = ft_strjoin(ft_strjoin(name, "="), new_value);
	}
	else
	{
		add_env_var(name, new_value);
	}
}

void	delete_env_var(char *name)
{
	int		i;
	int		k;
	int		var_to_be_removed;
	char	**new_ms_env;
	int		size;

	i = -1;
	k = 0;
	var_to_be_removed = locate_env_var(name);
	size = env_len(g_ms_env) - 1;
	new_ms_env = malloc((sizeof(char *) * size) + 1);
	while (g_ms_env[++i])
	{
		if (i != var_to_be_removed)
			new_ms_env[k++] = ft_strdup(g_ms_env[i]);
	}
	new_ms_env[k] = NULL;
	freeenv(&g_ms_env);
	g_ms_env = new_ms_env;
}
