/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/14 18:54:28 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../libft/libft.h" 
#include "stdio.h"

void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.5265);
	*y = (*x + *y) * sin(0.5265) - z;
}

void	cavalier(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.78539) + z * sin(0.78539);
	*y = (*x + *y) * sin(0.7071067812) - z * cos(0.7071067812);
}

double	get_angle(int x, int y, int x1, int y1, int z, int z1)
{
	double	dx;
	double	dy;
	double	dz;

	dx = x1 - x;
	dy = y1 - y;
	dz = z1 - z;
	return (atan2(dz, dy));
}

void	get_rotation_x(int *y, int *z, double alpha)
{
	double	tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(alpha) + *z * sin(alpha);
	*z = -tmp_y * sin(alpha) + *z * cos(alpha);
}

void	get_rotation_y(int *x, int *z, double beta)
{
	int	tmp_x;

	tmp_x = *x;
	*x = tmp_x * sin(beta) + *z * cos(beta);
	*z = -tmp_x * sin(beta) + *z * cos(beta);
}

void	get_rotation_z(int *x, int *y, double gamma)
{
	int	tmp_x;
	int	tmp_y; 

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(gamma) - tmp_y * sin(gamma);
	*x = tmp_x * cos(gamma) + tmp_y * sin(gamma);
}
