/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:12:40 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/06 12:49:38 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	adding(t_room *room, t_lemin *lemin)
{
	t_neigh	*tmp1;
	t_neigh	*tmp2;

	tmp1 = room->neighbors;
	while (tmp1)
	{
		tmp2 = tmp1->room->neighbors;
		while (tmp2)
		{
			if (tmp1->room->way + tmp1->room->plus >
				tmp2->room->way + tmp2->room->plus)
				break ;
			tmp2 = tmp2->next_neigh;
		}
		if (!tmp2 && ft_strcmp(tmp1->room->name, lemin->end->name))
		{
			tmp1->room->plus++;
			adding(tmp1->room, lemin);
		}
		tmp1 = tmp1->next_neigh;
	}
	return (0);
}

int	plus_one(t_lemin *lemin, t_ant *ant)
{
	int i;

	i = 0;
	while ((ant->room_way)[i] &&
		ft_strcmp(((ant->room_way)[i])->name, lemin->end->name))
	{
		if (ft_strcmp(((ant->room_way)[i])->name, lemin->end->name))
		{
			((ant->room_way[i]))->plus++;
			adding((ant->room_way)[i], lemin);
		}
		i++;
	}
	return (0);
}
