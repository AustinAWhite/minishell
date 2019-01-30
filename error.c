/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:59:48 by awhite            #+#    #+#             */
/*   Updated: 2019/01/26 00:18:46 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_error_basic(char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
}

void	ms_error_arg(char *message, char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(arg, STDERR_FILENO);
}

void	ms_error_envv(char *name)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putendl_fd(": undefined variable", STDERR_FILENO);
}

void	ms_unmatched_quotes(int unmatched)
{
	ft_putstr_fd("Unmatched: ", STDERR_FILENO);
	ft_putchar_fd(unmatched, STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
}