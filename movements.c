/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:44:14 by yechen            #+#    #+#             */
/*   Updated: 2018/05/12 14:07:07 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_left(t_all *data)
{
	data->olddir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rot_speed) - data->dir_y
		* sin(data->rot_speed);
	data->dir_y = data->olddir_x * sin(data->rot_speed) +
		data->dir_y * cos(data->rot_speed);
	data->oldplane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(data->rot_speed) - data->plane_y *
		sin(data->rot_speed);
	data->plane_y = data->oldplane_x * sin(data->rot_speed) + data->plane_y *
		cos(data->rot_speed);
}

void		move_right(t_all *data)
{
	data->olddir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->rot_speed) - data->dir_y *
		sin(-data->rot_speed);
	data->dir_y = data->olddir_x * sin(-data->rot_speed) + data->dir_y *
		cos(-data->rot_speed);
	data->oldplane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->rot_speed) - data->plane_y *
		sin(-data->rot_speed);
	data->plane_y = data->oldplane_x * sin(-data->rot_speed) + data->plane_y *
		cos(-data->rot_speed);
}

void		move_down(t_all *data)
{
	if (data->map[(int)(data->pos_x - data->dir_x
				* data->move_speed)][(int)data->pos_y]
			== 0)
		data->pos_x -= data->dir_x * data->move_speed;
	if (data->map[(int)data->pos_x][(int)(data->pos_y
				- data->dir_y * data->move_speed)]
			== 0)
		data->pos_y -= data->dir_y * data->move_speed;
}

void		move_up(t_all *data)
{
	if (data->map[(int)(data->pos_x + data->dir_x
				* data->move_speed)][(int)data->pos_y]
			== 0)
		data->pos_x += data->dir_x * data->move_speed;
	if (data->map[(int)data->pos_x][(int)(data->pos_y + data->dir_y *
				data->move_speed)] == 0)
		data->pos_y += data->dir_y * data->move_speed;
}

void		key_movements(t_all *data)
{
	initialize_movement(data);
	while (SDL_PollEvent(&data->event))
	{
		if (data->event.type == SDL_QUIT)
			data->running = 1;
		if (data->event.type == SDL_KEYDOWN)
		{
			if (data->event.key.keysym.sym == SDLK_ESCAPE)
				data->running = 1;
			if (data->event.key.keysym.sym == SDLK_UP ||
					data->event.key.keysym.sym == SDLK_w)
				move_up(data);
			if (data->event.key.keysym.sym == SDLK_DOWN ||
					data->event.key.keysym.sym == SDLK_s)
				move_down(data);
			if (data->event.key.keysym.sym == SDLK_RIGHT ||
					data->event.key.keysym.sym == SDLK_d)
				move_right(data);
			if (data->event.key.keysym.sym == SDLK_LEFT ||
					data->event.key.keysym.sym == SDLK_a)
				move_left(data);
		}
	}
}
