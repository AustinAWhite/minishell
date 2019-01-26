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

static int		ms_read_line(char **line)
{
	char	*tmp;
	char	buf[2];
	int		unmatched;

	unmatched = 0;
	*line = ft_strnew(1);
	while (read(STDIN_FILENO, buf, 1) > 0)
	{
		buf[1] = '\0';
		if (buf[0] == '\n')
			break;
		if (set_vals(buf[0], &unmatched) > 0)
			continue;
		if (buf[0] != '\\')
		{
			tmp = ft_strjoin(*line, buf);
			free(*line);
			*line = tmp;
		}
	}
	return (unmatched);
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
	char	unmatched;

	status = 1;
	while (status)
	{
		args = NULL;
		ft_putstr("$> ");
		if ((unmatched = ms_read_line(&line)) > 0)
		{
			ft_putstr_fd("Unmatched ", STDERR_FILENO);
			ft_putchar_fd(unmatched, STDERR_FILENO);
			ft_putendl_fd("", STDERR_FILENO);
			continue;
		}
		if (ft_strlen(line) != 0)
			args = ms_split_line(line);
		if (args != NULL)
			status = ms_execute(args);
		free(args);
		free(line);
	}
}
