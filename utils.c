/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:22:37 by awhite            #+#    #+#             */
/*   Updated: 2019/01/26 00:30:26 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ms_num_builtins(void)
{
	int num;

	num = 0;
	while (g_builtin_str[num])
		num++;
	return (num);
}

void	freeenv(char ***ms_env)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = *ms_env;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

char	**ft_strarrdup(char **str)
{
	int		i;
	int		size;
	char	**new;

	i = -1;
	size = env_len(str);
	new = (char **)malloc((sizeof(char *) * size) + 1);
	while (++i < size)
		new[i] = ft_strdup(str[i]);
	new[i] = NULL;
	return (new);
}
