/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:48:41 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/16 18:41:48 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "stdio.h"
#include <stdlib.h>

char	*free_mem(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	return (NULL);
}

int	get_steep_sx(int *x, int *x1, t_point *point)
{
	point->sx = malloc(sizeof(int));
	*(point -> sx) = 0;
	if (*x < *x1)
		*(point->sx) = 1;
	else
		*(point->sx) = -1;
	return (*(point->sx));
}

int	get_steep_sy(int *y, int *y1, t_point *point)
{
	point->sy = malloc(sizeof(int));
	*(point->sy) = 0;
	if (*y < *y1)
		*(point->sy) = 1;
	else
		*(point->sy) = -1;
	return (*(point->sy));
}

void	zoom(t_point *point, int *begin, int *end)
{
	begin[0] *= point -> zoom;
	begin[1] *= point -> zoom;
	end[0] *= point -> zoom;
	end[1] *= point -> zoom;
}

void	shift(t_point *point, int *begin, int *end)
{
	begin[0] += point -> shift_x;
	end[0] += point -> shift_x;
	begin[1] += point -> shift_y;
	end[1] += point -> shift_y;
}
