/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:25:37 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/06 11:30:58 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*create_empty_lem(void)
{
	t_lemin *lem;

	lem = (t_lemin*)malloc(sizeof(t_lemin));
	lem->rlist = NULL;
	lem->cants = -1;
	lem->start = NULL;
	lem->end = NULL;
	lem->ants = NULL;
	lem->steps = 0;
	lem->crooms = 0;
	return (lem);
}

t_room			*create_empty_room(void)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	room->neighbors = NULL;
	room->next_room = NULL;
	room->status = 0;
	room->plus = 0;
	room->way = INT_MAX;
	room->ant = NULL;
	return (room);
}

t_ant			*create_ant(t_room *start, int max_way)
{
	static int	i;
	t_ant		*ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->location = start;
	ant->nbr = ++i;
	ant->room_way = (t_room**)malloc((max_way + 1) * sizeof(t_room*));
	ft_bzero(ant->room_way, (max_way + 1) * sizeof(t_room*));
	ant->rw_index = 0;
	ant->cur_room_i = -1;
	return (ant);
}

void			init_ants(t_lemin *lem)
{
	int	i;

	lem->ants = (t_ant**)malloc(sizeof(t_ant) * (lem->cants + 1));
	(lem->ants)[lem->cants] = NULL;
	i = 0;
	while (i < lem->cants)
	{
		(lem->ants)[i] = create_ant(lem->start, lem->crooms);
		i++;
	}
}
