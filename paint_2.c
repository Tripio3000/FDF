/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:06:27 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/08 00:06:29 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_fdf *data)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (data->deltax > data->deltay)
		percentage = percent(data->start.x, data->end.x, data->x);
	else
		percentage = percent(data->start.y, data->end.y, data->y);
	red = get_light((data->start.color >> 16) & 0xFF,
	(data->end.color >> 16) & 0xFF, percentage);
	green = get_light((data->start.color >> 8) & 0xFF,
	(data->end.color >> 8) & 0xFF, percentage);
	blue = get_light(data->start.color & 0xFF,
	data->end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		intermediate_color(t_fdf *data, int z)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	percentage = percent(data->min_z, data->max_z, z);
	red = get_light((data->min_color >> 16) & 0xFF,
	(data->max_color >> 16) & 0xFF, percentage);
	green = get_light((data->min_color >> 8) & 0xFF,
	(data->max_color >> 8) & 0xFF, percentage);
	blue = get_light(data->min_color & 0xFF,
	data->max_color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	get_z(t_fdf *data)
{
	data->z = (float)data->arr[(int)data->y][(int)data->x];
	data->z1 = (float)data->arr[(int)data->y1][(int)data->x1];
	data->start.color = intermediate_color(data, data->z);
	data->end.color = intermediate_color(data, data->z1);
	data->x -= data->widht / 2;
	data->x1 -= data->widht / 2;
	data->y -= data->lenght / 2;
	data->y1 -= data->lenght / 2;
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->z *= data->zoom_z;
	data->z1 *= data->zoom_z;
}

float	maximum(float a, float b)
{
	return ((a > b) ? a : b);
}
