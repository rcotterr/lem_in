/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:45:43 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/06 11:44:12 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	recursion(t_room *start, t_room *room, int way, t_room *prev)
{
	t_neigh	*tmp;

	tmp = room->neighbors;
	while (tmp)
	{
		if (way < tmp->room->way)
		{
			tmp->room->way = way;
			if (ft_strcmp(tmp->room->name, start->name) &&
						ft_strcmp(tmp->room->name, prev->name))
				recursion(start, tmp->room, way + 1, room);
		}
		tmp = tmp->next_neigh;
	}
	return (0);
}

int	put_ways(t_lemin *lemin)
{
	int		way;
	t_room	*tmp;

	way = 0;
	lemin->end->way = way++;
	recursion(lemin->start, lemin->end, way, lemin->end);
	tmp = lemin->start;
	while (tmp)
	{
		ft_putnbr(tmp->way);
		tmp = tmp->next_room;
	}
	if (lemin->start->way == INT_MAX)
		crash("there is no way");
	return (0);
}
