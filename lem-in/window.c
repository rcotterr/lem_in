/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:04:03 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/06 12:25:07 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	count_scale(t_lemin *lemin, t_visual *visual)
{
	int		max_x;
	int		max_y;
	int		scale_x;
	int		scale_y;
	t_room	*tmp;

	tmp = lemin->rlist;
	max_x = 1;
	max_y = 1;
	while (tmp)
	{
		if (tmp->x > max_x)
			max_x = tmp->x;
		if (tmp->y > max_y)
			max_y = tmp->y;
		tmp = tmp->next_room;
	}
	scale_x = 1100 / max_x;
	scale_y = 600 / max_y;
	visual->scale = ((scale_x > scale_y) ? scale_y : scale_x);
	visual->x0 = 640 - max_x * visual->scale / 2;
	visual->y0 = 360 - max_y * visual->scale / 2;
	if ((visual->radius = visual->scale / 3) > 50)
		visual->radius = 50;
	return (0);
}

int	put_rooms(t_lemin *lemin, t_visual visual)
{
	t_room	*tmp;
	t_neigh	*neigh;

	tmp = lemin->rlist;
	while (tmp)
	{
		neigh = tmp->neighbors;
		while (neigh)
		{
			draw_line(*tmp, *(neigh->room), visual);
			neigh = neigh->next_neigh;
		}
		if (tmp == lemin->end)
			draw_circle(visual, *tmp, visual.radius, 0x32CD32);
		else if (tmp == lemin->start)
			draw_circle(visual, *tmp, visual.radius, 0xFF69B4);
		else
			draw_circle(visual, *tmp, visual.radius, 0xFFFFFF);
		tmp = tmp->next_room;
	}
	mlx_string_put(visual.mlx_ptr, visual.win_ptr,
		50, 700, 0xFFFFFF, "Press left mouse button for movement");
	mlx_string_put(visual.mlx_ptr, visual.win_ptr,
		1000, 20, 0xFFFFFF, "Start - pink, End - green");
	return (0);
}

int	change_coordinates(t_lemin *lemin, t_visual visual)
{
	t_room	*tmp;

	tmp = lemin->rlist;
	while (tmp)
	{
		tmp->x = tmp->x * visual.scale + visual.x0;
		tmp->y = tmp->y * visual.scale + visual.y0;
		tmp = tmp->next_room;
	}
	return (0);
}

int	moving(t_lemin *lemin, t_ant *ant, int j, t_visual *visual)
{
	if (ant->location == lemin->start)
	{
		if (!(((ant->room_way)[j])->status) || (ant->room_way)[j] == lemin->end)
		{
			ant->location = (ant->room_way)[j];
			((ant->room_way)[j])->status++;
			draw_ant(visual, *((ant->room_way)[j]));
		}
		else
			draw_ant(visual, *(lemin->start));
		return (0);
	}
	while ((ant->room_way)[j] != ant->location)
		j++;
	if (!(((ant->room_way)[j + 1])->status) ||
		(ant->room_way)[j + 1] == lemin->end)
	{
		((ant->room_way)[j])->status = 0;
		ant->location = (ant->room_way)[++j];
		((ant->room_way)[j])->status++;
		draw_ant(visual, *((ant->room_way)[j]));
	}
	return (0);
}

int	move_ants(t_lemin *lemin, t_visual *visual)
{
	int		i;
	int		j;
	t_ant	*ant;

	i = 0;
	j = 0;
	while (i < lemin->cants)
	{
		ant = (lemin->ants)[i];
		if (ant->location != lemin->end)
			moving(lemin, ant, j, visual);
		i++;
	}
	return (0);
}
