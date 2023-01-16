/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:46:41 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/16 14:33:33 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include "fdf_struct.h"
# include <limits.h>
# include <math.h>

int			get_height(char *path);
int			get_width(char *path);
char		**get_map(char *path);
void		get_matrix(char *path, t_point *point);
void		wu_algo(t_data data);
void		drawline(t_point *point);
void		isometric(int *x, int *y, int z);
void		key_hook(void *param);
void		conic(int *x, int *y, int center_x, int center_y, double radius);
double		get_angle(int x, int y, int x1, int y1, int z, int z1);
/* void	get_rotation_x(int *x, int *y, double angle);
void	get_rotation_y(int *x, int *y, double angle); */
void		get_rotation_x(int *y, int *z, double alpha);
void		get_rotation_y(int *x, int *z, double beta);
void		get_rotation_z(int *x, int *y, double gamma);
void		cavalier(int *x, int *y, int z);
char		*free_mem(char **s);
void		zoom(t_data *data);
t_coords	*get_coords(t_point *point);
int			get_steep_sx(int *x, int *x1, t_point *point);
int			get_steep_sy(int *y, int *y1, t_point *point);

#endif
