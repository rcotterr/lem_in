/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:48:25 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/07 19:34:38 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	del(char **line)
{
	free(*line);
	*line = NULL;
}

static int	ri_error(char **line)
{
	del(line);
	return (-1);
}

static int	ri_line_help(char **line)
{
	int ret;

	del(line);
	ret = get_next_line(0, line);
	if (ret > 0)
		ft_putendl(*line);
	if (ret == -1)
		crash("Read error!");
	return (ret);
}

int			read_input(t_lemin *lem)
{
	char	*line;
	int		special;
	int		ret_value;

	special = 0;
	line = NULL;
	while (ri_line_help(&line))
	{
		ret_value = read_comment(line, &special);
		if (ret_value == -1)
			return (ri_error(&line));
		if (ret_value == 1)
			continue;
		if (lem->cants == -1 && (lem->cants = count_ants(line)))
			continue;
		if ((ret_value = read_room(lem, line, &special)) == -1 ||
			(special && ret_value == 0))
			return (ri_error(&line));
		if (ret_value != 1 && read_connection(lem, line) == -1)
			return (ri_error(&line));
	}
	del(&line);
	return (1);
}
