/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:15:27 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/07 18:43:38 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "get_next_line.h"
# include "libft/libft.h"
# include <limits.h>
# include "mlx.h"

typedef struct s_room	t_room;

typedef struct		s_neigh
{
	t_room			*room;
	struct s_neigh	*next_neigh;
}					t_neigh;

typedef struct		s_ant
{
	int				nbr;
	int				rw_index;
	int				cur_room_i;
	t_room			*location;
	t_room			**room_way;
}					t_ant;

struct				s_room
{
	char			*name;
	int				status;
	int				way;
	int				plus;
	int				x;
	int				y;
	t_ant			*ant;
	t_neigh			*neighbors;
	t_room			*next_room;
};

typedef struct		s_lemin
{
	t_room			*start;
	t_room			*end;
	t_room			*rlist;
	t_ant			**ants;
	int				cants;
	int				steps;
	int				crooms;
}					t_lemin;

typedef struct		s_visual
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				scale;
	int				x0;
	int				y0;
	int				radius;
	int				mouse;
	t_lemin			*lemin;
}					t_visual;

typedef struct		s_draw
{
	float			err;
	float			derr;
	int				step_x;
	int				step_y;
	int				x;
	int				y;
	int				delta;
	int				error;
}					t_draw;

int					count_ants(char *ants);
int					read_room(t_lemin *lem, char *line, int *special);
int					read_comment(char *line, int *special);
int					read_connection(t_lemin *lem, char *line);
int					read_input(t_lemin *lem);
t_room				*find_room_by_name(t_room *rlist, char *name);
void				add_neigh(t_room *r1, t_room *r2);
void				print_room(t_room *room);
void				print_lemin(t_lemin *lem);
void				print_ants(t_lemin *lem);
void				add_room(t_lemin *lem, t_room *room);
t_lemin				*create_empty_lem();
t_room				*create_empty_room();
t_room				*to_room(char *line);
void				free_split(char ***split);
int					ways_length(t_lemin *lemin);
void				crash(char *reason);
int					count_scale(t_lemin *lemin, t_visual *visual);
int					put_rooms(t_lemin *lemin, t_visual visual);
int					change_coordinates(t_lemin *lemin, t_visual visual);
int					move_ants(t_lemin *lemin, t_visual *visual);
void				draw_circle(t_visual vis, t_room rm, int radius, int col);
void				draw_line(t_room room1, t_room room2, t_visual vis);
void				draw_ant(t_visual *visual, t_room room);
int					make_ant_ways(t_lemin *lemin);
void				init_ants(t_lemin *lem);
void				chose_way(t_lemin *lem, t_ant *ant);
int					plus_one(t_lemin *lemin, t_ant *ant);
void				making_steps(t_lemin *lemin);
int					check_jam(t_lemin *lemin, t_ant *ant1);
void				reset_room_ants(t_room *rlist);
void				free_lem(t_lemin **lemin);
void				check(t_lemin *lemin);

#endif
