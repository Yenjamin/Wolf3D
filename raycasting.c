#include "wolf.h"

void		dda(t_all *data)
{
	while (data->hit == 0)
	{
		if (data->sidedist_x < data->sidedist_y)
		{
			data->sidedist_x += data->deltadist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->sidedist_y += data->deltadist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_x][data->map_y] > 0)
			data->hit = 1;
	}
    draw(data);
}

void		side_dist(t_all *data)
{
	if (data->raydir_x < 0)
	{
		data->step_x = -1;
		data->sidedist_x = (data->pos_x - data->map_x) * data->deltadist_x;
	}
	else
	{
		data->step_x = 1;
		data->sidedist_x = (data->map_x + 1.0 - data->pos_x) * data->deltadist_x;
	}
	if (data->raydir_y < 0)
	{
		data->step_y = -1;
		data->sidedist_y = (data->pos_y - data->map_y) * data->deltadist_y;
	}
	else
	{
		data->step_y = 1;
		data->sidedist_y = (data->map_y + 1.0 - data->pos_y) * data->deltadist_y;
	}
	dda(data);
}

void		raycasting(t_all *data)
{
	data->camera_x = 2 * data->x / (double)data->width - 1;
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->deltadist_x = sqrt(1 + (data->raydir_y * data->raydir_y) /
			(data->raydir_x * data->raydir_x));
	data->deltadist_y = sqrt(1 + (data->raydir_x * data->raydir_x) /
			(data->raydir_y * data->raydir_y));
    data->hit = 0;
    side_dist(data);
}