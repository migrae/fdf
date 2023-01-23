/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:21:20 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/23 15:08:03 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_pixel(t_map *map, int x, int y, uint32_t color)
{
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
		mlx_put_pixel(map->image, x, y, color);
}

t_coords	update_points(t_coords point, t_data *data)
{
	point.x *= data->factor;
	point.y *= data->factor;
	point.z *= data->factor / data->map.z_height;
	point.y -= (data->map.height * data->factor) / 2;
	point.x -= (data->map.width * data->factor) / 2;
	point.x = (point.x - point.y) * cos(0.5265);
	point.y = (-point.z + point.x + point.y) * sin(0.5265);
	point.x += WIDTH / 2 + data->offset_x;
	point.y += HEIGHT / 2 + data->offset_y;
	return (point);
}

void	draw_line(t_map map, t_coords start, t_coords end)
{
	double	dx;
	double	dy;
	double	pix_x;
	double	pix_y;
	int		put_pix;

	dx = end.x - start.x;
	dy = end.y - start.y;
	put_pix = sqrt((dx * dx) + (dy * dy));
	dx /= put_pix;
	dy /= put_pix;
	pix_x = start.x;
	pix_y = start.y;
	while (put_pix)
	{
		draw_pixel(&map, pix_x, pix_y, 0x5bf0a8);
		pix_x = pix_x + dx;
		pix_y = pix_y + dy;
		put_pix--;
	}
}

void	draw_grid(t_data *data)
{
	int	i;

	i = 0;
	ft_bzero(data->map.image->pixels, WIDTH * HEIGHT * 4);
	while (i < data->map.pixel)
	{
		if (data->map.points[i + 1] != NULL && (i + 1) % data->map.width != 0)
		{
			draw_line(data->map, update_points(*data->map.points[i], data),
				update_points(*data->map.points[i + 1], data));
		}
		if ((i / data->map.width) < (data->map.height - 1)
			&& data->map.points[i + data->map.width])
		{
			draw_line(data->map, update_points(*data->map.points[i], data),
				update_points(*data->map.points[i + data->map.width], data));
		}
		i++;
	}
}
