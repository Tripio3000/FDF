/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <efleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:59:42 by cseabass          #+#    #+#             */
/*   Updated: 2020/02/05 11:10:39 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_wd(char *line, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= 48 && line[i] <= 57)
		{
			counter++;
			while (line[i] != c && line[i] != '\0')
				i++;
			continue;
		}
		i++;
	}
	return (counter);
}

int		get_lenght(char *filename)
{
	int		lenght;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	lenght = 0;
	while (get_next_line(fd, &line))
	{
		lenght++;
		free(line);
	}
	close(fd);
	return (lenght);
}

int		get_widht(char *filename)
{
	int		widht;
	int		fd;
	char	*line;
	int		g;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (error());
	g = get_next_line(fd, &line);
	if (g < 0)
		return (error());
	widht = check_wd(line, ' ');
	free(line);
	close(fd);
	return (widht);
}

int		fill_arr(char *line, t_fdf *data, int j)
{
	char	**mas;
	int		i;

	mas = ft_strsplit(line, ' ');
	i = 0;
	while (i < data->widht)
	{
		if (mas[i] == NULL)
			return (error());
		data->arr[j][i] = ft_atoi(mas[i]);
		free(mas[i]);
		i++;
	}
	free(mas);
	return (0);
}

void	read_file(char *filename, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->widht = get_widht(filename);
	data->lenght = get_lenght(filename);
	data->arr = (int **)malloc(sizeof(int *) * (data->lenght + 1));
	i = 0;
	while (i <= data->lenght)
	{
		data->arr[i] = ft_memalloc(sizeof(int) * (data->widht));
		i++;
	}
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_arr(line, data, i);
		free(line);
		i++;
	}
	close(fd);
}
