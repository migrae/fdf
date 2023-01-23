/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:20:06 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/20 17:17:20 by mgraefen         ###   ########.fr       */
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
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->map.height++;
		data->map.width = ft_count_word(line, ' ');
		line = get_next_line(fd);
	}
	data->map.pixel = (data->map.height * data->map.width);
	if (close(fd) == -1)
	{
		ft_printf("close() error");
		return (free(line), 0);
	}
	return (free(line), 0);
}

int	get_matrix(char *filename, t_data *data)
{
	char	**temp;
	char	*line;
	int		i;
	int		j;
	int		fd;
	int		count;

	j = 0;
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("open() error");
		return (0);
	}
	data->map.points = ft_calloc(data->map.height * data->map.width,
			sizeof (t_coords*));
	if (!data->map.points)
		return (free_map(&data->map), free(data), 0);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_split(line, ' ');
		i = 0;
		while (temp[i])
		{
			data->map.points[count] = ft_calloc(1, sizeof(t_coords));
			if (!data->map.points[count])
				return (free_temp(temp), free(line), 0);
			data->map.points[count]->x = i;
			data->map.points[count]->y = j;
			data->map.points[count]->z = ft_atoi(temp[i]);
			count++;
			i++;
		}
		free_temp(temp);
		line = get_next_line(fd);
		j++;
	}
	data->map.points[count] = NULL;
	free(line);
	if (close(fd) == -1)
	{
		ft_printf("close() error");
		return (free_map(&data->map), free(data), 0);
	}
	return (0);
}

void	ft_map_reader(t_data *data, char *filename)
{	
	get_map_size(filename, data);
	get_matrix(filename, data);
}
