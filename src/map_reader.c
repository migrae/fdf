/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:20:06 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/23 14:17:24 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_map_size(char *filename, t_data *data)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("open() error");
		finish(data, 0);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->map.height++;
		data->map.width = ft_count_word(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
	{
		ft_printf("close() error");
		finish(data, 0);
	}
	return (0);
}

void	write_coords(char *line, int j, t_data *data)
{
	char	**temp;
	int		i;

	temp = ft_split(line, ' ');
	i = 0;
	while (temp[i])
	{
		data->map.points[data->map.pixel] = ft_calloc(1, sizeof(t_coords));
		if (!data->map.points[data->map.pixel])
		{
			free_temp(temp);
			finish(data, 0);
		}
		data->map.points[data->map.pixel]->x = i;
		data->map.points[data->map.pixel]->y = j;
		data->map.points[data->map.pixel]->z = ft_atoi(temp[i]);
		data->map.pixel += 1;
		i++;
	}
	free_temp(temp);
}

void	prep_coords(int fd, t_data *data)
{
	char	*line;
	int		j;

	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		write_coords(line, j, data);
		free(line);
		line = get_next_line(fd);
		j++;
	}
	/* free(line); */
	data->map.points[data->map.pixel] = NULL;
}

int	get_matrix(char *filename, t_data *data)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("open() error");
		finish(data, 0);
	}
	data->map.points = ft_calloc(data->map.height * data->map.width,
			sizeof (t_coords*));
	if (!data->map.points)
		finish(data, 0);
	prep_coords(fd, data);
	if (close(fd) == -1)
	{
		ft_printf("close() error");
		finish(data, 0);
	}
	return (0);
}

void	ft_map_reader(t_data *data, char *filename)
{	
	get_map_size(filename, data);
	get_matrix(filename, data);
}
