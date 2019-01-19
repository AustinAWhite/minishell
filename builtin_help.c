/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:24:00 by awhite            #+#    #+#             */
/*   Updated: 2019/01/18 18:24:28 by awhite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ms_builtin_help(char **args)
{
	int		fd;
	char	*filename;
	char	*line;

	args = NULL;
	filename = "resources/help.txt";
	if ((fd = open(filename, O_RDONLY)) < 0)
		ms_error_arg("file not found", filename);
	if (fd > 0)
	{
		while (get_next_line(fd, &line))
			ft_putendl(line);
	}
	return (1);
}
