/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:53:49 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/23 09:54:01 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_data(t_data *data, char *filename)
{
	ft_map_reader(data, filename);
	data->factor = 25;
	data->map.z_height = 5;
	data->offset_x = 0;
	data->offset_y = 0;
}

int32_t	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (EXIT_FAILURE);
	data->map.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->map.mlx)
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	init_data(data, argv[1]);
	data->map.image = mlx_new_image(data->map.mlx, WIDTH, HEIGHT);
	draw_grid(data);
	mlx_image_to_window(data->map.mlx, data->map.image, 0, 0);
	mlx_loop_hook(data->map.mlx, &keys, &data->map);
	mlx_loop(data->map.mlx);
	finish(data);
	/* system("leaks FDF"); */
	return (EXIT_SUCCESS);
}
