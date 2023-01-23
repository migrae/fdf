/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:31:47 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/23 09:43:31 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	finish(t_data *data)
{
	mlx_delete_image(data->map.mlx, data->map.image);
	mlx_terminate(data->map.mlx);
	free_map(&data->map);
	free(data);
	exit(EXIT_SUCCESS);
}

void	keys(void *in)
{
	t_data	*data;

	data = (t_data *)in;
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_ESCAPE))
		finish(data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_DOWN))
		edit_factor(MLX_KEY_DOWN, data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_UP))
		edit_factor(MLX_KEY_UP, data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_W))
		move(MLX_KEY_W, data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_S))
		move(MLX_KEY_S, data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_A))
		move(MLX_KEY_A, data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_D))
		move(MLX_KEY_D, data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_KP_ADD))
		edit_z_height(MLX_KEY_KP_ADD, data);
	if (mlx_is_key_down(data->map.mlx, MLX_KEY_KP_SUBTRACT))
		edit_z_height(MLX_KEY_KP_SUBTRACT, data);
}