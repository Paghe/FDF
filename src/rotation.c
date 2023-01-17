/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:21:21 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/17 12:21:57 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../libft/libft.h" 
#include "stdio.h"

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
