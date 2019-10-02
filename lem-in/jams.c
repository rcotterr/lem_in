/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jams.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:06:20 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/07 16:26:18 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reset_room_ants(t_room *rlist)
{
	t_room *room;

	room = rlist;
	while (room)
	{
		room->ant = NULL;
		room = room->next_room;
	}
}

void	free_array(t_room **tmp)
{
	int i;

	i = 0;
	while (tmp && tmp[i])
		free(tmp[i++]);
	if (tmp)
		free(tmp);
}

void	swap_ant_ways(t_lemin *lemin, t_ant *ant1, t_ant *ant2)
{
	t_room	**tmp;
	int		i;

	i = 0;
	tmp = (t_room **)malloc(sizeof(t_room *) * (lemin->crooms + 1));
	while ((ant1->room_way)[ant1->cur_room_i + i + 1])
	{
		tmp[i] = (ant1->room_way)[ant1->cur_room_i + i + 1];
		i++;
	}
	tmp[i] = NULL;
	i = 1;
	while (tmp[i])
	{
		(ant2->room_way)[ant2->cur_room_i + i] = tmp[i];
		i++;
	}
	(ant2->room_way)[ant2->cur_room_i + i] = NULL;
	ant2->rw_index = ant2->cur_room_i + i;
	while (ant2->cur_room_i + i < lemin->start->way)
	{
		(ant2->room_way)[ant2->cur_room_i + i] = NULL;
		i++;
	}
	free_array(tmp);
}

int		check_jam(t_lemin *lemin, t_ant *ant1)
{
	t_room	*current;
	t_room	*want_room1;
	t_room	*want_room2;
	t_ant	*ant2;

	current = (ant1->room_way)[ant1->cur_room_i];
	want_room1 = (ant1->room_way)[ant1->cur_room_i + 1];
	ant2 = want_room1->ant;
	while (ant2)
	{
		want_room2 = ((ant2->room_way)[ant2->cur_room_i + 1]);
		if (want_room2 == current && ant2 != ant1)
		{
			reset_room_ants(lemin->rlist);
			swap_ant_ways(lemin, ant1, ant2);
			return (1);
		}
		want_room1 = (ant2->room_way)[ant2->cur_room_i + 1];
		ant2 = want_room1->ant;
	}
	return (0);
}
