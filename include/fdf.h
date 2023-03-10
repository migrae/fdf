/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:17:54 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/24 11:20:00 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include "../Libft/get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_coords
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_coords;

typedef struct s_map
{
	int			height;
	int			width;
	int			pixel;
	int			z_height;
	t_coords	**points;
	mlx_image_t	*image;
	mlx_t		*mlx;
}				t_map;

typedef struct s_data
{
	t_map	map;
	int		factor;
	int		offset_x;
	int		offset_y;
	int		x;
	int		y;
	double	x_rotate;
	double	y_rotate;
	double	z_rotate;
}			t_data;

void		ft_map_reader(t_data *data, char *filename);
int			get_map_size(char *filename, t_data *data);
void		write_coords(char *line, int j, t_data *data);
void		prep_coords(int fd, t_data *data);
int			get_matrix(char *filename, t_data *data);

void		draw_grid(t_data *data);
void		draw_pixel(t_map *map, int x, int y, uint32_t color);
t_coords	update_points(t_coords point, t_data *data);
void		draw_line(t_map map, t_coords start, t_coords end);

void		keys(void *in);

void		free_data(t_data *data);
void		free_temp(char **temp);
void		finish(t_data *data, int e);

void		edit_factor(int key, t_data *data);
void		move(int key, t_data *data);
void		edit_z_height(int key, t_data *data);

t_coords	rotate_x(t_coords point, double x_rotate);
t_coords	rotate_y(t_coords point, double y_rotate);
t_coords	rotate_z(t_coords point, double z_rotate);

void		mouse_drag(t_data *data);

#endif
