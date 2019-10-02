/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:12:13 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/07 19:31:22 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_lemin	*lem;
	int		r;

	lem = create_empty_lem();
	r = read_input(lem);
	check(lem);
	if (r == -1 || lem->rlist == NULL)
		crash("Invalid Map!");
	write(1, "\n", 1);
	ways_length(lem);
	make_ant_ways(lem);
	making_steps(lem);
	exit(0);
}
