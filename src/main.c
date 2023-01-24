/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:53:49 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/24 11:08:48 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_data(t_data *data, char *filename)
{
	data->map.pixel = 0;
	ft_map_reader(data, filename);
	data->factor = 25;
	data->map.z_height = 5;
	data->offset_x = 0;
	data->offset_y = 0;
	data->x_rotate = 0;
	data->y_rotate = 0;
	data->z_rotate = 0;
	data->x = 0;
	data->y = 0;
}

int32_t	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (EXIT_FAILURE);
	data->map.mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!data->map.mlx)
		return (free(data), EXIT_FAILURE);
	init_data(data, argv[1]);
	data->map.image = mlx_new_image(data->map.mlx, WIDTH, HEIGHT);
	if (!data->map.image)
		return (free_data(data), EXIT_FAILURE);
	draw_grid(data);
	mlx_image_to_window(data->map.mlx, data->map.image, 0, 0);
	mlx_loop_hook(data->map.mlx, &keys, &data->map);
	mlx_loop(data->map.mlx);
	mlx_delete_image(data->map.mlx, data->map.image);
	mlx_terminate(data->map.mlx);
	free_data(data);
	return (EXIT_SUCCESS);
}
