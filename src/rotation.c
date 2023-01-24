/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:32:21 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/24 11:13:40 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_coords	rotate_x(t_coords point, double x_rotate)
{
	int	y;
	int	z;

	z = point.z;
	y = point.y;
	point.z = -y * sin(x_rotate) + z * cos(x_rotate);
	point.y = y * cos(x_rotate) + z * sin(x_rotate);
	return (point);
}

t_coords	rotate_y(t_coords point, double y_rotate)
{
	int	x;
	int	z;

	x = point.x;
	z = point.z;
	point.x = x * cos(y_rotate) + z * sin(y_rotate);
	point.z = -x * sin(y_rotate) + z * cos(y_rotate);
	return (point);
}

t_coords	rotate_z(t_coords point, double z_rotate)
{
	int	x;
	int	y;

	x = point.x;
	y = point.y;
	point.x = x * cos(z_rotate) - y * sin(z_rotate);
	point.y = x * sin(z_rotate) + y * cos(z_rotate);
	return (point);
}
