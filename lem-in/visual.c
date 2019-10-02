/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:11:41 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/06 15:38:57 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		deal_key(int key, void *visual)
{
	if ((int)key == 53)
	{
		mlx_destroy_window(((t_visual *)visual)->mlx_ptr,
			((t_visual *)visual)->win_ptr);
		exit(0);
	}
	return (0);
}

int		deal_mouse(int mouse, int x, int y, void *vis)
{
	x = 0;
	y = 0;
	if ((int)mouse == 1)
	{
		mlx_clear_window(((t_visual *)vis)->mlx_ptr,
			((t_visual *)vis)->win_ptr);
		if (++((t_visual *)vis)->mouse > ((t_visual *)vis)->lemin->steps)
		{
			mlx_string_put(((t_visual *)vis)->mlx_ptr,
				((t_visual *)vis)->win_ptr, 640, 360, 0xFFFFFF, "THE END");
			mlx_string_put(((t_visual *)vis)->mlx_ptr,
				((t_visual *)vis)->win_ptr, 50, 700, 0xFFFFFF, "Press escape");
			return (0);
		}
		put_rooms(((t_visual *)vis)->lemin, *((t_visual *)vis));
		move_ants(((t_visual *)vis)->lemin, (t_visual *)vis);
	}
	return (0);
}

void	window(t_lemin *lemin)
{
	t_visual	vis;

	if (!(vis.mlx_ptr = mlx_init()))
		exit(0);
	if (!(vis.win_ptr = mlx_new_window(vis.mlx_ptr, 1280, 720, "lem-in")))
		exit(0);
	if (lemin->crooms > 50)
	{
		mlx_string_put(vis.mlx_ptr,
				vis.win_ptr, 640, 360, 0xFFFFFF, "TOO MANY ROOMS");
		mlx_string_put(vis.mlx_ptr, vis.win_ptr, 50, 50, 0xFFFFFF, "Press esc");
	}
	else
	{
		count_scale(lemin, &vis);
		change_coordinates(lemin, vis);
		put_rooms(lemin, vis);
		if (lemin->cants > 0)
			draw_ant(&vis, *(lemin->start));
		vis.lemin = lemin;
		vis.mouse = 0;
		mlx_hook(vis.win_ptr, 4, 1, deal_mouse, &vis);
	}
	mlx_hook(vis.win_ptr, 2, 1, deal_key, &vis);
	mlx_loop(vis.mlx_ptr);
}

int		main(void)
{
	t_lemin	*lem;
	int		r;

	lem = create_empty_lem();
	r = read_input(lem);
	write(1, "\n", 1);
	if (r == -1 || lem->rlist == NULL)
		crash("Invalid Map!");
	ways_length(lem);
	make_ant_ways(lem);
	making_steps(lem);
	window(lem);
	exit(0);
}
