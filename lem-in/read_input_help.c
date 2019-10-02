/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:40:00 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/07 19:34:55 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	read_comment(char *line, int *special)
{
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			if (ft_strcmp(line, "##start") == 0)
			{
				if (!(*special))
					*special = 1;
				else
					return (-1);
			}
			else if (ft_strcmp(line, "##end") == 0)
			{
				if (*special)
					return (-1);
				*special = 2;
			}
			return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	read_room(t_lemin *lem, char *line, int *special)
{
	t_room	*room;

	room = to_room(line);
	if (room == NULL)
		return (0);
	lem->crooms += 1;
	if (find_room_by_name(lem->rlist, room->name))
		return (-1);
	add_room(lem, room);
	if (*special == 1)
	{
		if (!lem->start)
			lem->start = find_room_by_name(lem->rlist, room->name);
		else
			return (-1);
	}
	else if (*special == 2)
	{
		if (!lem->end)
			lem->end = find_room_by_name(lem->rlist, room->name);
		else
			return (-1);
	}
	*special = 0;
	return (1);
}

int	read_connection(t_lemin *lem, char *line)
{
	char	**split;
	int		split_len;
	t_room	*r1;
	t_room	*r2;

	split = ft_strsplit(line, '-');
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 2)
	{
		free_split(&(split));
		return (-1);
	}
	r1 = find_room_by_name(lem->rlist, split[0]);
	r2 = find_room_by_name(lem->rlist, split[1]);
	if (!r1 || !r2)
		return (-1);
	else
		add_neigh(r1, r2);
	free_split(&(split));
	return (1);
}
