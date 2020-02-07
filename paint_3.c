/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:02:59 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/08 00:03:04 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ugladian(int a)
{
	float	k;

	k = (a * M_PI) / 180;
	return (k);
}

void	rot_x(float *y, float *z, t_fdf *data)
{
	float	pr_y;
	float	pr_z;

	pr_y = *y;
	pr_z = *z;
	*y = pr_y * cos(ugladian(data->angle_x)) +
	pr_z * sin(ugladian(data->angle_x));
	*z = -pr_y * sin(ugladian(data->angle_x)) +
	pr_z * cos(ugladian(data->angle_x));
}

void	rot_y(float *x, float *z, t_fdf *data)
{
	float	pr_x;
	float	pr_z;

	pr_x = *x;
	pr_z = *z;
	*x = pr_x * cos(ugladian(data->angle_y)) +
	pr_z * sin(ugladian(data->angle_y));
	*z = -pr_x * sin(ugladian(data->angle_y)) +
	pr_z * cos(ugladian(data->angle_y));
}

void	rot_z(float *x, float *y, t_fdf *data)
{
	float	pr_x;
	float	pr_y;

	pr_x = *x;
	pr_y = *y;
	*x = pr_x * cos(ugladian(data->angle_z)) -
	pr_y * sin(ugladian(data->angle_z));
	*y = pr_x * sin(ugladian(data->angle_z)) +
	pr_y * cos(ugladian(data->angle_z));
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}
