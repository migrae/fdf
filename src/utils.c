/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:17:15 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/23 15:10:00 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.points[i])
	{
		free(data->map.points[i]);
		i++;
	}
	free(data->map.points);
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
	mlx_delete_image(data->map.mlx, data->map.image);
	mlx_terminate(data->map.mlx);
	free_data(data);
	/* system("leaks FDF"); */
	if (e)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
