/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:04:18 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:09:13 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*join_args(char **args, int n_flag)
{
	int i;
	char *joined;
	char *tmp;

	(n_flag) ? (i = 1) : (i = 0);
	joined = ft_strnew(1);
	while (args[++i])
	{
		tmp = ft_strjoin(joined, args[i]);
		free(joined);
		joined = tmp;
		if (args[i + 1])
		{
			tmp = ft_strjoin(joined, " ");
			free(joined);
			joined = tmp;
		}
	}
	return (joined);
}

static int		set_vals(char c, int *unmatched)
{
	if (IS_QUOTE(c) && *unmatched == 0)
	{
		*unmatched = c;
		return (1);
	}
	if (IS_QUOTE(c) && c == *unmatched)
	{
		*unmatched = 0;
		return (1);
	}
	return (0);
}

static int	print_args(char **args, int n_flag)
{
	int i;
	int unmatched;
	char *joined;
	char *formatted;
	char *tmp;

	i = -1;
	unmatched = 0;
	joined = join_args(args, n_flag);
	formatted = ft_strnew(1);
	while (joined[++i])
	{
		if ((set_vals(joined[i], &unmatched)) > 0)
			continue;
		if (joined[i] != '\\')
		{
			tmp = ft_strchrjoin(formatted, joined[i]);
			free(formatted);
			formatted = tmp;
		}
	}
	(unmatched) ? (ms_unmatched_quotes(unmatched)) : (ft_putstr(formatted));
	return (unmatched);
}

int			ms_builtin_echo(char **args)
{
	int i;
	int n_flag;
	int unmatched;

	i = 0;
	n_flag = 0;
	if (!args[1])
	{
		ft_putchar('\n');
		return (1);
	}
	if (args[1][0] == '-' && args[1][1] == 'n' && args[1][2] == '\0')
	{
		n_flag = 1;
		i++;
	}
	unmatched = print_args(args, n_flag);
	if (!n_flag && unmatched == 0)
		ft_putchar('\n');
	return (1);
}
