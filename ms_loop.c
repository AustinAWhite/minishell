/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:20:38 by awhite            #+#    #+#             */
/*   Updated: 2019/01/26 00:29:45 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**split_line(char *line)
{
	int i;
	char **split_line;

	i = -1;
	while(line[++i])
		if (!ft_strchr(WHITESPACE, line[i]))
			break;
	if (i == (int)ft_strlen(line))
		return (NULL);
	split_line = ft_strtok_mod(line, WHITESPACE);
	if ((check_expansions(split_line)) || do_expansions(&split_line) > 0)
		return (NULL);
	return (split_line);
}

void			ms_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		args = NULL;
		ft_putstr("$> ");
		get_next_line(0, &line);
		args = split_line(line);
		if (args != NULL)
			status = ms_execute(args);
		free(args);
		free(line);
	}
}
