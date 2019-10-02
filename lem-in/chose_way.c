/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 01:30:06 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/07 19:10:33 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	closest_len(t_neigh *neigh)
{
	int		cl_len;
	int		len;
	t_neigh	*n;

	cl_len = INT_MAX;
	n = neigh;
	while (n)
	{
		len = n->room->way + n->room->plus;
		if (len < cl_len)
			cl_len = len;
		n = n->next_neigh;
	}
	return (cl_len);
}

static int	count_connection(t_neigh *neigh)
{
	int		neigh_count;

	neigh_count = 0;
	while (neigh)
	{
		neigh = neigh->next_neigh;
		neigh_count++;
	}
	return (neigh_count);
}

t_neigh		*closest_neigh(t_neigh *neigh)
{
	int		cl_len;
	int		neigh_count;
	int		nc2;
	t_neigh *cl_neigh;

	cl_len = closest_len(neigh);
	neigh_count = INT_MAX;
	cl_neigh = NULL;
	nc2 = 0;
	while (neigh)
	{
		if (cl_len == neigh->room->way + neigh->room->plus)
		{
			if ((cl_neigh == NULL) ||
				((nc2 = count_connection(neigh)) < neigh_count))
			{
				cl_neigh = neigh;
				neigh_count = nc2;
			}
		}
		neigh = neigh->next_neigh;
	}
	return (cl_neigh);
}

void		chose_way(t_lemin *lem, t_ant *ant)
{
	t_room	*current_room;
	t_room	*closest_room;

	current_room = lem->start;
	while (current_room != lem->end)
	{
		closest_room = (closest_neigh(current_room->neighbors))->room;
		(ant->room_way)[ant->rw_index] = closest_room;
		(ant->rw_index) += 1;
		current_room = closest_room;
	}
}
