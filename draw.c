#include "wolf.h"

void		draw(t_all *data)
{
	if (data->side == 0)
		data->perpwall_dist = (data->map_x - data->pos_x +
				(1 - data->step_x) / 2) / data->raydir_x;
	else
		data->perpwall_dist = (data->map_y - data->pos_y +
				(1 - data->step_y) / 2) / data->raydir_y;
	data->line_height = (int)(data->height / data->perpwall_dist);
	data->draw_start = -data->line_height + data->height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height + data->height / 2;
	if (data->draw_end >= data->height)
		data->draw_end = data->height - 1;
	wall_color(data);
}

void		wall_color(t_all *data)
{
	data->y = data->draw_start;
	if (data->side == 0)
		SDL_SetRenderDrawColor(data->renderer, 0, 0, 255, 255);
	if (data->side != 0)
		SDL_SetRenderDrawColor(data->renderer, 255, 0, 0, 255);
	if (data->side == 0 && data->raydir_x < 0)
		SDL_SetRenderDrawColor(data->renderer, 0, 255, 0, 255);
	if (data->side == 1 && data->raydir_y < 0)
        SDL_SetRenderDrawColor(data->renderer, 255, 0, 255, 255);
	while (data->y < data->draw_end)
	{
		SDL_RenderDrawPoint(data->renderer, data->x, data->y);
		data->y++;
	}
}