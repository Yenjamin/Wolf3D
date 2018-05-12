/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:44:48 by yechen            #+#    #+#             */
/*   Updated: 2018/05/12 15:15:19 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <SDL2/SDL.h>
# include "libft/libft.h"
# include <math.h>

typedef struct		s_all
{
	int				max_x;
	int				max_y;
	double			**map;
	int				x;
	int				y;
	int				fd;
	char			**split;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	int				height;
	int				width;
	int				running;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	SDL_Event		event;
	double			olddir_x;
	double			oldplane_x;
}					t_all;

void				error(char *str);
void				max_size(char *str, t_all *data);
void				map_alloc(char *str, t_all *data);
void				reader(char *str, t_all *data);
void				initialize_variable(t_all *data);
void				initialize_sdl(t_all *data);
void				raycasting(t_all *data);
void				side_dist(t_all *data);
void				dda(t_all *data);
void				draw(t_all *data);
void				wall_color(t_all *data);
void				initialize_movement(t_all *data);
void				key_movements(t_all *data);

#endif
