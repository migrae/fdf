/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:17:15 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/23 09:53:10 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->points[i])
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
	/* free(map); */
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
