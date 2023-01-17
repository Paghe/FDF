/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:56 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/17 12:30:14 by apaghera         ###   ########.fr       */
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

double	get_angle(int y, int y1, int z, int z1)
{
	double	dy;
	double	dz;

	dy = abs(y1 - y);
	dz = abs(z1 - z);
	return (atan2(dz, dy));
}
