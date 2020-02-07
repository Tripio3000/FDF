/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:08:18 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/08 00:08:19 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_zbuffer(t_fdf *data)
{
	int	i;

	data->z_buffer = (int *)malloc(sizeof(int) * WIDTH * HEIGHT);
	i = -1;
	while (++i < HEIGHT * WIDTH)
		data->z_buffer[i] = -2147483648;
}

void	init_zoom(t_fdf *data)
{
	if (data->widht < 100 && data->lenght < 100)
		data->zoom = 50;
	else if (data->widht >= 100 && data->lenght >= 100)
		data->zoom = 5;
	else
		data->zoom = 30;
}

void	init_var(t_fdf *data)
{
	data->per = 800;
	init_zoom(data);
	data->shift_x = 0;
	data->shift_y = 0;
	data->angle_x = -30;
	data->angle_y = -30;
	data->angle_z = 30;
	data->min_color = 0x7BFF55;
	data->max_color = 0xE400FF;
	data->projection = 0;
	data->p = 0;
	data->zoom_z = 25;
}

int		usage(void)
{
	ft_putstr("usage: <filename>\n");
	exit(0);
}

int		error(void)
{
	ft_putstr("error\n");
	exit(0);
}
