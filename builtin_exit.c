/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:11:06 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:11:17 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ms_builtin_exit(char **args)
{
	if (args[1])
	{
		ft_putendl_fd("exit: Expression Syntax.", STDERR_FILENO);
		return (1);
	}
	return (0);
}
