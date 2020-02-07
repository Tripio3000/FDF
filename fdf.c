/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <efleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:59:13 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/07 18:26:06 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_z(int key, t_fdf *data)
{
	if (key == 6 && data->zoom_z > 1)
		data->zoom_z -= 1;
	if (key == 7 && data->zoom_z <= 25)
		data->zoom_z += 1;
}

int		key_press(int key, t_fdf *data)
{
	int i;

	i = -1;
	view(key, data);
	press_key_3(key, data);
	zoom_z(key, data);
	change_zoom(key, data);
	gradient(key, data);
	change_per(key, data);
	if (data->p == 1)
		data->angle_z = 30;
	while (++i < WIDTH * HEIGHT)
		data->color[i] = 0;
	key_press_2(data);
	return (0);
}

void	minmax_z(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lenght)
	{
		j = 0;
		while (j < data->widht)
		{
			if (data->arr[i][j] < data->min_z)
				data->min_z = data->arr[i][j];
			if (data->arr[i][j] > data->max_z)
				data->max_z = data->arr[i][j];
			j++;
		}
		i++;
	}
}

void	z_zero(t_fdf *data)
{
	int	i;

	i = -1;
	while (++i < HEIGHT * WIDTH)
		data->z_buffer[i] = -2147483648;
}

int		main(int argc, char **argv)
{
	t_fdf	*data;

	data = ft_memalloc(sizeof(t_fdf));
	if (argc == 1)
		return (usage());
	else if (argc == 2)
		read_file(argv[1], data);
	else
		return (error());
	ft_menu();
	init_zbuffer(data);
	init_var(data);
	minmax_z(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->color = (int *)mlx_get_data_addr(data->img_ptr,
		&(data->n0), &(data->n1), &(data->n2));
	data->color[0] = 0xffffff;
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 0, key_press, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
