/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:11 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/23 14:32:52 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	edit_factor(int key, t_data *data)
{
	if (key == MLX_KEY_UP)
		data->factor += 1;
	else if (key == MLX_KEY_DOWN)
	{
		data->factor -= 1;
		if (data->factor < 1)
			data->factor = 1;
	}
	draw_grid(data);
}

void	move(int key, t_data *data)
{
	if (key == MLX_KEY_S)
		data->offset_y += 10;
	if (key == MLX_KEY_W)
		data->offset_y -= 10;
	if (key == MLX_KEY_D)
		data->offset_x -= 10;
	if (key == MLX_KEY_A)
		data->offset_x += 10;
	draw_grid(data);
}

void	edit_z_height(int key, t_data *data)
{
	if (key == MLX_KEY_KP_SUBTRACT)
		data->map.z_height += 1;
	if (key == MLX_KEY_KP_ADD)
	{
		data->map.z_height -= 1;
		if (data->map.z_height < 1)
			data->map.z_height = 1;
	}
	draw_grid(data);
}
