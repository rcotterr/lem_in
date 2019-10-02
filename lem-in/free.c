/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:29:59 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/06 11:30:57 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_split(char ***split)
{
	int		split_len;
	char	**sp;

	sp = *split;
	split_len = 0;
	while (sp[split_len])
		split_len++;
	while (--split_len >= 0)
		free(sp[split_len]);
	free(sp);
	*split = NULL;
}

void	free_room(t_room **room)
{
	if (!room)
		ft_putendl_fd("free_room received null instead of ptr", 2);
	else
	{
		free((*room)->name);
		(*room)->name = NULL;
		free(*room);
		room = NULL;
	}
}

void	free_rlist(t_room **rlist)
{
	t_room	*current;
	t_room	*next;

	if (!rlist)
		ft_putendl_fd("free_rlist received null instead of ptr", 2);
	else
	{
		current = *(rlist);
		while (current)
		{
			next = current->next_room;
			free(current);
			current = next;
		}
		*rlist = NULL;
	}
}

void	free_lem(t_lemin **lemin)
{
	int		i;
	t_ant	*ant;

	if (!lemin)
		ft_putendl_fd("free_lem received null instead of ptr", 2);
	else
	{
		if ((*lemin)->rlist)
			free_rlist(&((*lemin)->rlist));
		if ((*lemin)->ants)
		{
			i = 0;
			while (i < (*lemin)->cants)
			{
				ant = ((*lemin)->ants)[i];
				free(ant->room_way);
				ant->room_way = NULL;
				free(ant);
				ant = NULL;
				i++;
			}
		}
		free(*lemin);
		(*lemin) = NULL;
	}
}

void	crash(char *reason)
{
	write(1, "ERROR\n", 6);
	write(2, reason, ft_strlen(reason));
	write(2, "\n", 1);
	exit(-1);
}
