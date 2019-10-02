/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:11:10 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/06 12:28:30 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reset_ant(t_lemin *lemin, t_ant *ant)
{
	int i;

	i = 0;
	while (i < lemin->crooms + 1)
	{
		(ant->room_way)[i] = NULL;
		i++;
	}
	ant->rw_index = 0;
}

int		make_ant_ways(t_lemin *lemin)
{
	int i;

	if (!(lemin->ants))
		init_ants(lemin);
	i = 0;
	while (i < lemin->cants)
	{
		if (lemin->ants[i]->location == lemin->start)
		{
			reset_ant(lemin, (lemin->ants)[i]);
			chose_way(lemin, (lemin->ants)[i]);
			plus_one(lemin, (lemin->ants)[i]);
		}
		i++;
	}
	return (0);
}
