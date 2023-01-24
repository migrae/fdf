/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:03:29 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/24 11:15:46 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	mouse_drag(t_data *data)
{
	int	x;
	int	y;

	x = data->x;
	y = data->y;
	mlx_get_mouse_pos(data->map.mlx, &data->x, &data->y);
	if (mlx_is_mouse_down(data->map.mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		data->z_rotate += (data->x - x) * 0.002;
		data->x_rotate += (data->y - y) * 0.02;
		data->y_rotate += (data->x - x) * 0.02;
	}
	draw_grid(data);
}
