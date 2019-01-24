/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:20:38 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 17:22:25 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ms_read_line(void)
{
	char *line;

	line = NULL;
	get_next_line(STDIN_FILENO, &line);
	return (line);
}

static char		**ms_split_line(char *line)
{
	char **split_line;

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
		ft_putstr("$> ");
		line = ms_read_line();
		args = ms_split_line(line);
		if (args != NULL)
			status = ms_execute(args);
		free(args);
		free(line);
	}
}
