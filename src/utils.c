/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:17:15 by mgraefen          #+#    #+#             */
/*   Updated: 2023/02/09 10:11:02 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.points)
	{
		while (data->map.points[i])
		{
			free(data->map.points[i]);
			i++;
		}
		free(data->map.points);
	}
	free(data);
}

void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	finish(t_data *data, int e)
{
	if (data->map.mlx && data->map.image)
		mlx_delete_image(data->map.mlx, data->map.image);
	if (data->map.mlx)
		mlx_terminate(data->map.mlx);
	if (data)
		free_data(data);
	if (e)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
