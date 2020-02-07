/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:12:00 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/08 00:12:02 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press_2(t_fdf *data)
{
	z_zero(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void	press_key_3(int key, t_fdf *data)
{
	if (data->projection == 1)
		change_angle(key, data);
	if (key == 53)
		exit(0);
	else if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 123)
		data->shift_x -= 10;
}
