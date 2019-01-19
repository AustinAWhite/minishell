/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:22:37 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:23:31 by awhite           ###   ########.fr       */
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
