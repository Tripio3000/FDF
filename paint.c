/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:36:30 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/07 23:36:35 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *data, float z)
{
	if (data->x < 0 || data->x >= WIDTH || data->y < 0 || data->y >= HEIGHT)
		return ;
	if (data->z_buffer[WIDTH * (int)(data->y - 1) + (int)data->x] < (int)z)
	{
		data->color[WIDTH * (int)(data->y - 1)
		+ (int)data->x] = data->current_color;
		data->z_buffer[WIDTH * (int)(data->y - 1) + (int)data->x] = (int)z;
	}
}

void	rotation(t_fdf *data)
{
	get_z(data);
	rot_x(&data->y, &data->z, data);
	rot_x(&data->y1, &data->z1, data);
	rot_y(&data->x, &data->z, data);
	rot_y(&data->x1, &data->z1, data);
	rot_z(&data->x, &data->y, data);
	rot_z(&data->x1, &data->y1, data);
	find_step(data);
}

int		ft_kostil(t_fdf *data)
{
	if (data->start.z > (data->per * 0.99) || data->end.z > (data->per * 0.99))
		return (0);
	if (((int)data->x >= WIDTH && (int)data->x1 >= WIDTH)
		|| ((int)data->x <= 0 && (int)data->x1 <= 0)
		|| ((int)data->y >= HEIGHT && (int)data->y1 >= HEIGHT)
		|| ((int)data->y <= 0 && (int)data->y1 <= 0))
		return (0);
	return (1);
}

void	set_line(t_fdf *data)
{
	float	z;

	rotation(data);
	if (ft_kostil(data) == 0)
		return ;
	z = (data->start.z + data->end.z) / 2;
	while ((int)(data->x1 - data->x) != 0 || (int)(data->y1 - data->y) != 0)
	{
		if ((int)data->x >= WIDTH || (int)data->x <= 0
		|| (int)data->y >= HEIGHT || (int)data->y <= 0)
		{
			data->x += data->deltax;
			data->y += data->deltay;
			continue ;
		}
		data->current_color = get_color(data);
		put_pixel(data, z);
		data->x += data->deltax;
		data->y += data->deltay;
	}
	if (((int)(data->x1 - data->x) == 0 || (int)(data->y1 - data->y) == 0))
	{
		data->current_color = get_color(data);
		put_pixel(data, z);
	}
}

void	crutch(int x, int y, t_fdf *data)
{
	if (x < data->widht - 1)
	{
		data->x = x;
		data->x1 = x + 1;
		data->y = y;
		data->y1 = y;
		set_line(data);
	}
	if (y < data->lenght - 1)
	{
		data->x = x;
		data->x1 = x;
		data->y = y;
		data->y1 = y + 1;
		set_line(data);
	}
}
