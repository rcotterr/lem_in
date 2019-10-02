/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:33:47 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/06 11:30:52 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room			*find_room_by_name(t_room *rlist, char *name)
{
	t_room	*current;

	current = rlist;
	while (current && ft_strcmp(current->name, name))
	{
		current = current->next_room;
	}
	return (current);
}

t_room			*to_room(char *line)
{
	char		**split;
	int			split_len;
	t_room		*new_room;

	if (!(split = ft_strsplit(line, ' ')))
		return (NULL);
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
	{
		free_split(&(split));
		return (NULL);
	}
	new_room = create_empty_room();
	new_room->name = ft_strnew(ft_strlen(split[0]) * sizeof(char));
	ft_strcpy(new_room->name, split[0]);
	new_room->x = ft_atoi(split[1]);
	new_room->y = ft_atoi(split[2]);
	free_split(&(split));
	return (new_room);
}

void			add_to_neigh_list(t_room *room, t_neigh *neigh)
{
	t_neigh *current;

	if (!(room->neighbors))
		(room->neighbors) = neigh;
	else
	{
		current = room->neighbors;
		while (current && current->next_neigh)
			current = current->next_neigh;
		if (current)
			current->next_neigh = neigh;
	}
}

void			add_neigh(t_room *r1, t_room *r2)
{
	t_neigh	*new_neigh;

	new_neigh = (t_neigh*)malloc(sizeof(t_neigh));
	new_neigh->room = r2;
	new_neigh->next_neigh = NULL;
	add_to_neigh_list(r1, new_neigh);
	new_neigh = (t_neigh*)malloc(sizeof(t_neigh));
	new_neigh->next_neigh = NULL;
	new_neigh->room = r1;
	add_to_neigh_list(r2, new_neigh);
}

void			add_room(t_lemin *lem, t_room *room)
{
	t_room	*current;

	if (lem->rlist)
	{
		current = lem->rlist;
		while (current->next_room)
			current = current->next_room;
		current->next_room = room;
	}
	else
		lem->rlist = room;
	room->next_room = NULL;
}
