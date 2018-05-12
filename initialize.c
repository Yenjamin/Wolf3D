/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:43:02 by yechen            #+#    #+#             */
/*   Updated: 2018/05/12 14:08:16 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	initialize_sdl(t_all *data)
{
	data->running = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		error("SDL Error");
	data->window = SDL_CreateWindow("Wolf 3D",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			data->width, data->height, 0);
	data->renderer = SDL_CreateRenderer(data->window,
			-1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(data->renderer, 0, 0, 0, 255);
	SDL_RenderClear(data->renderer);
}

void	initialize_variable(t_all *data)
{
	data->pos_x = data->max_x / 2;
	data->pos_y = data->max_y / 2;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->time = 0;
	data->old_time = 0;
	data->height = 600;
	data->width = 1000;
	initialize_sdl(data);
}

void	initialize_movement(t_all *data)
{
	data->x = 0;
	data->old_time = data->time;
	data->time = SDL_GetTicks();
	data->frame_time = (data->time - data->old_time) / 1000.0;
	SDL_RenderPresent(data->renderer);
	SDL_SetRenderDrawColor(data->renderer, 0, 0, 0, 255);
	SDL_RenderClear(data->renderer);
	data->move_speed = data->frame_time * 7.0;
	data->rot_speed = data->frame_time * 4.0;
}
