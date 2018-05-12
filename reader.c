/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:44:37 by yechen            #+#    #+#             */
/*   Updated: 2018/05/12 15:37:05 by yechen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	max_size(char *str, t_all *data)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	line = NULL;
	data->max_y = 1;
	if (get_next_line(fd, &line) > 0)
		data->max_x = ft_countword(line);
	while (get_next_line(fd, &line) > 0)
		data->max_y++;
	close(fd);
	map_alloc(str, data);
}

void	reader(char *str, t_all *data)
{
	char	*line;

	max_size(str, data);
	data->y = 0;
	data->fd = open(str, O_RDONLY);
	while (get_next_line(data->fd, &line) > 0 && data->y < data->max_y)
	{
		if ((ft_countword(line)) >= data->max_x)
		{
			data->split = ft_strsplit(line, ' ');
			data->x = -1;
			while (data->x < data->max_x)
			{
				data->map[data->y][data->x] = ft_atoi(data->split[data->x]);
				data->x++;
			}
			ft_free2d(data->split);
			data->y++;
			if (data->max_x <= 1)
				error("map too small");
		}
		else
			error("Uneven Map");
	}
	close(data->fd);
}

void	map_alloc(char *str, t_all *data)
{
	int		i;

	i = 0;
	data->map = (double **)malloc(sizeof(double *) * data->max_y);
	while (i < data->max_y)
	{
		data->map[i] = (double *)malloc(sizeof(double) * data->max_x);
		i++;
	}
}
