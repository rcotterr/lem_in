/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:03:12 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/07 16:25:34 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		print_way(int nbr, char *str, int *sp)
{
	write(1, "L", 1);
	ft_putnbr(nbr);
	write(1, "-", 1);
	ft_putstr(str);
	(*sp)++;
	return (0);
}

int		steps(t_lemin *lemin, t_ant *ant, int *sp)
{
	if (!(((ant->room_way)[ant->cur_room_i + 1])->status) ||
		(ant->room_way)[ant->cur_room_i + 1] == lemin->end)
	{
		if (*sp)
			write(1, " ", 1);
		if (ant->cur_room_i != -1)
			((ant->room_way)[ant->cur_room_i])->status = 0;
		ant->cur_room_i++;
		ant->location = (ant->room_way)[ant->cur_room_i];
		((ant->room_way)[ant->cur_room_i])->status++;
		print_way(ant->nbr, ((ant->room_way)[ant->cur_room_i])->name, sp);
	}
	else if (ant->cur_room_i != -1)
	{
		((ant->room_way)[ant->cur_room_i])->ant = ant;
		check_jam(lemin, ant);
	}
	return (0);
}

void	reset_plus(t_lemin *lemin)
{
	t_room	*rptr;

	rptr = lemin->rlist;
	while (rptr)
	{
		rptr->plus = 0;
		rptr = rptr->next_room;
	}
}

void	making_steps(t_lemin *lemin)
{
	int		i;
	int		sp;
	t_ant	*ant;

	i = 0;
	sp = 0;
	while (lemin->end->status < lemin->cants)
	{
		while (i < lemin->cants)
		{
			ant = (lemin->ants)[i];
			if (ant->location != lemin->end)
				steps(lemin, ant, &sp);
			i++;
		}
		i = 0;
		sp = 0;
		lemin->steps++;
		reset_room_ants(lemin->rlist);
		write(1, "\n", 1);
		reset_plus(lemin);
		make_ant_ways(lemin);
	}
	while (i < lemin->cants)
		((lemin->ants)[i++])->location = lemin->start;
}
