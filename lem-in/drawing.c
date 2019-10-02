/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:50:56 by rcotter-          #+#    #+#             */
/*   Updated: 2019/08/06 12:01:17 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	draw_circle(t_visual vis, t_room rm, int radius, int col)
{
	t_draw	dr;

	dr.x = 0;
	dr.y = radius;
	dr.error = 0;
	dr.delta = 1 - 2 * radius;
	while (dr.y >= 0)
	{
		mlx_pixel_put(vis.mlx_ptr, vis.win_ptr, rm.x + dr.x, rm.y + dr.y, col);
		mlx_pixel_put(vis.mlx_ptr, vis.win_ptr, rm.x + dr.x, rm.y - dr.y, col);
		mlx_pixel_put(vis.mlx_ptr, vis.win_ptr, rm.x - dr.x, rm.y + dr.y, col);
		mlx_pixel_put(vis.mlx_ptr, vis.win_ptr, rm.x - dr.x, rm.y - dr.y, col);
		dr.error = 2 * (dr.delta + dr.y) - 1;
		if ((dr.delta < 0) && (dr.error <= 0))
		{
			dr.delta = dr.delta + 2 * ++dr.x + 1;
			continue ;
		}
		if ((dr.delta > 0) && (dr.error > 0))
		{
			dr.delta = dr.delta - 2 * --dr.y + 1;
			continue ;
		}
		dr.delta = dr.delta + 2 * (++dr.x - --dr.y);
	}
}

void	draw_line(t_room room1, t_room room2, t_visual vis)
{
	t_draw	draw;

	draw.step_x = (room2.x > room1.x) ? 1 : -1;
	draw.step_y = (room2.y > room1.y) ? 1 : -1;
	if (room1.x == room2.x)
	{
		while ((room1.y += draw.step_y) != room2.y + draw.step_y)
			mlx_pixel_put(vis.mlx_ptr, vis.win_ptr, room1.x, room1.y, 0xFFFFFF);
		return ;
	}
	draw.err = 0.0;
	draw.derr = (float)(room2.y - room1.y) / (float)(room2.x - room1.x);
	draw.derr = (draw.derr > 0) ? draw.derr : -draw.derr;
	while ((room1.x += draw.step_x) != room2.x + draw.step_x)
	{
		mlx_pixel_put(vis.mlx_ptr, vis.win_ptr, room1.x, room1.y, 0xFFFFFF);
		draw.err += draw.derr;
		while (draw.err >= 0.5)
		{
			room1.y += draw.step_y;
			draw.err -= 1.0;
			mlx_pixel_put(vis.mlx_ptr, vis.win_ptr, room1.x, room1.y, 0xFFFFFF);
		}
	}
}

void	draw_ant(t_visual *visual, t_room room)
{
	int i;

	i = 0;
	while (i++ < visual->radius / 3)
		draw_circle(*visual, room, visual->radius / 3 - i, 0xA52A2A);
	room.y = room.y + visual->radius / 3;
	i = 0;
	while (i++ < visual->radius / 5)
		draw_circle(*visual, room, visual->radius / 5 - i, 0xA52A2A);
}
