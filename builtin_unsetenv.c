/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:12:12 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:12:24 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ms_builtin_unsetenv(char **args)
{
	if (args[1])
	{
		if (locate_env_var(args[1]) >= 0)
			delete_env_var(args[1]);
	}
	return (1);
}
