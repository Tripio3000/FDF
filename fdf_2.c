/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:09:32 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/08 00:09:34 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_angle(int key, t_fdf *data)
{
	if (key == 83)
		data->angle_x -= 2;
	if (key == 84)
		data->angle_x += 2;
	if (key == 86)
		data->angle_y -= 2;
	if (key == 87)
		data->angle_y += 2;
	if (key == 89)
		data->angle_z -= 2;
	if (key == 91)
		data->angle_z += 2;
}

void	change_zoom(int key, t_fdf *data)
{
	if (key == 78 && data->zoom > 1)
		data->zoom -= 1;
	if (key == 69 && data->zoom <= 100)
		data->zoom += 1;
}

void	gradient(int key, t_fdf *data)
{
	if (key == 18)
	{
		data->min_color = 0xAA00FF;
		data->max_color = 0x32FF00;
	}
	if (key == 19)
	{
		data->min_color = 0x7BFF55;
		data->max_color = 0xE400FF;
	}
	if (key == 20)
	{
		data->min_color = 0x5A5A5A;
		data->max_color = 0xFF6C00;
	}
	if (key == 21)
	{
		data->min_color = 0x0023FF;
		data->max_color = 0xFF6800;
	}
}

void	change_per(int key, t_fdf *data)
{
	if (key == 35)
		data->p = 1;
	if (data->per > 600 && data->p == 1)
	{
		if (key == 116)
			data->per -= 25;
	}
	if (key == 121 && data->p == 1)
		data->per += 25;
}

void	view(int key, t_fdf *data)
{
	if (key == 15)
	{
		data->projection = 1;
		data->angle_x = -21;
		data->angle_y = -21;
		data->angle_z = 21;
	}
	if (key == 34)
	{
		data->p = 0;
		data->projection = 0;
		data->angle_x = -30;
		data->angle_y = -30;
		data->angle_z = 30;
	}
	if (key == 31)
	{
		data->p = 0;
		data->projection = 0;
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0;
	}
}
