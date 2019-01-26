/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 00:17:22 by awhite            #+#    #+#             */
/*   Updated: 2019/01/26 00:17:24 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		locate_env_var(char *name)
{
	int i;
	int k;

	i = -1;
	while (g_ms_env[++i])
	{
		k = 0;
		while (name[k] == g_ms_env[i][k])
			k++;
		if (g_ms_env[i][k] == '=' && name[k] == '\0')
			return (i);
	}
	return (-1);
}

char	*get_env_var(char *name)
{
	int i;

	if ((i = locate_env_var(name)) >= 0)
		return (g_ms_env[i]);
	else
		return ("");
}

char	*get_envv_name(char *arg)
{
	int		i;
	int		j;
	int		len;
	char	*name;

	i = 0;
	j = -1;
	len = 0;
	if (!ENV_CHAR(arg[0]) || !arg)
		return (NULL);
	while (ENV_CHAR(arg[len]))
		len++;
	name = ft_strnew(len);
	while (++j < len)
		name[j] = arg[i++];
	name[j] = '\0';
	return (name);
}

int		validate_env_input(char *name, char *val)
{
	while (*name)
	{
		if (!ENV_CHAR(*name))
		{
			ft_putendl_fd("invalid character", STDERR_FILENO);
			return (1);
		}
		name++;
	}
	while (*val)
	{
		if (!ENV_CHAR(*val))
		{
			ft_putendl_fd("invalid character", STDERR_FILENO);
			return (1);
		}
		val++;
	}
	return (0);
}
