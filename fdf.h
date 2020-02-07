/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <efleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:59:25 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/07 23:25:01 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1300
# define HEIGHT 1300
# define ZOOM 50
# define ANGLE 30

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef struct	s_fdf
{
	int			lenght;
	int			widht;
	int			**arr;
	int			zoom;
	int			zoom_z;
	float		z;
	float		z1;
	float		x;
	float		x1;
	float		y;
	float		y1;
	float		deltax;
	float		deltay;
	int			projection;
	int			per;
	int			p;
	int			shift_x;
	int			shift_y;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	int			max_z;
	int			min_z;
	int			max_color;
	int			min_color;
	int			current_color;
	int			*color;
	int			*z_buffer;
	int			n0;
	int			n1;
	int			n2;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_point		start;
	t_point		end;
}				t_fdf;

int				check_wd(char *line, char c);
int				get_lenght(char *filename);
int				ge1t_widht(char *filename);
int				fill_arr(char *line, t_fdf *data, int j);
void			put_pixel(t_fdf *data, float z);
void			crutch(int x, int y, t_fdf *data);
void			find_step(t_fdf *data);
void			get_z(t_fdf *data);
int				intermediate_color(t_fdf *data, int z);
int				get_color(t_fdf *data);
int				get_light(int start, int end, double percentage);
float			ugladian(int a);
void			rot_x(float *y, float *z, t_fdf *data);
void			rot_y(float *x, float *z, t_fdf *data);
void			rot_z(float *x, float *y, t_fdf *data);
double			percent(int start, int end, int current);
int				ft_new_line(char **s, char **line, int fd, int ret);
int				get_next_line(const int fd, char **line);
void			zoom_z(int key, t_fdf *data);
int				key_press(int key, t_fdf *data);
void			minmax_z(t_fdf *data);
void			z_zero(t_fdf *data);
void			init_zbuffer(t_fdf *data);
void			init_zoom(t_fdf *data);
void			init_var(t_fdf *data);
int				usage(void);
void			change_angle(int key, t_fdf *data);
void			change_zoom(int key, t_fdf *data);
void			gradient(int key, t_fdf *data);
void			change_per(int key, t_fdf *data);
void			view(int key, t_fdf *data);
void			read_file(char *filename, t_fdf *data);
int				get_widht(char *filename);
void			set_line(t_fdf *data);
void			draw(t_fdf *data);
void			init_zbuffer(t_fdf *data);
void			z_zero(t_fdf *data);
int				error(void);
void			find_step_2(t_fdf *data);
void			key_press_2(t_fdf *data);
void			press_key_3(int key, t_fdf *data);
int				ft_kostil(t_fdf *data);
void			rotation(t_fdf *data);
float			mod(float a);
float			maximum(float a, float b);

#endif
