/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:34:32 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/16 15:21:21 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H 

# include "fdf.h"

typedef struct s_coords
{
	int		*x;
}			t_coords;

typedef struct s_point
{
	int		width;
	int		height;
	int		**z;
	void	*img;
	mlx_t	*mlx;
	int		zoom;
	long	color;
	int		shift_x;
	int		shift_y;
	double	x;
	double	x1;
	double	y;
	double	y1;
	int		*sx;
	int		*sy;
	double	alpha;
	double	beta;
	double	gamma;
}	t_point;

typedef struct s_data
{
	t_point	*point;
	int		x;
	int		y;
	int		x1;
	int		y1;
}			t_data;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

#endif
