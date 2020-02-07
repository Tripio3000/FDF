/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:58:45 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/08 01:30:00 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->lenght)
	{
		x = 0;
		while (x < data->widht)
		{
			crutch(x, y, data);
			x++;
		}
		y++;
	}
}

void	find_step(t_fdf *data)
{
	float	max;
	float	koef;
	float	koef1;

	if (data->p == 1)
	{
		koef = data->per / (data->per - data->z);
		koef1 = data->per / (data->per - data->z1);
		data->x = data->x * koef;
		data->y = data->y * koef;
		data->x1 = data->x1 * koef1;
		data->y1 = data->y1 * koef1;
	}
	data->deltax = data->x1 - data->x;
	data->deltay = data->y1 - data->y;
	max = maximum(mod(data->deltax), mod(data->deltay));
	data->deltax /= max;
	data->deltay /= max;
	data->x += WIDTH / 2;
	data->x1 += WIDTH / 2;
	data->y += HEIGHT / 2;
	data->y1 += HEIGHT / 2;
	find_step_2(data);
}

void	find_step_2(t_fdf *data)
{
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
	data->start.x = data->x;
	data->start.y = data->y;
	data->start.z = data->z;
	data->end.z = data->z1;
	data->end.x = data->x1;
	data->end.y = data->y1;
}

float	mod(float a)
{
	return ((a > 0) ? a : -a);
}

void	ft_menu(void)
{
	ft_putstr("\n\nAloha! I'm sure this is not the best FDF in history, ");
	ft_putstr("but I think it deserves a little bit of your attention.\n");
	ft_putstr("\n******************************************************");
	ft_putstr("******************************************************\n\n");
	ft_putstr("You should click on the following buttons:\n");
	ft_putstr("R - rotation\n");
	ft_putstr("1,2,4,5,7,8 (on the right side) - to change angle of view\n");
	ft_putstr("I - isometric view\n");
	ft_putstr("O - view from above\n");
	ft_putstr("P - perspective\n");
	ft_putstr("up arrow, down arrow - to change coefficient of perspective\n");
	ft_putstr("Z,X - to change z-zoom\n");
	ft_putstr("1,2,3,4 (on the left side) - to change color theme\n");
	ft_putstr("-,+ - to change zoom\n");
	ft_putstr("\n******************************************************");
	ft_putstr("******************************************************\n");
}
