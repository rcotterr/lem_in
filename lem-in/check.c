/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:16:07 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/07 19:35:55 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check(t_lemin *lemin)
{
	if (!(lemin->start) || !(lemin->end))
		crash("There is no start or end!");
}

int		count_ants(char *ants)
{
	long int	ac;
	int			i;

	ac = 0;
	i = 0;
	if (!ants)
		return (-1);
	while (ants[i])
	{
		if (!(ants[i] >= '0' && ants[i] <= '9'))
		{
			ac = -1;
			break ;
		}
		ac = ac * 10 + ants[i] - '0';
		i++;
	}
	if (ac > INT_MAX || ac <= 0)
	{
		free(ants);
		crash("Invalid ants number!");
	}
	return (ac);
}
