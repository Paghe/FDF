/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:42:23 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/16 15:43:02 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../libft/libft.h" 
#include "stdio.h"

void	wu_algo(t_data data)
{
	int			err;
	int			z;
	int			z1;

	z = data.point -> z[data.y][data.x];
	z1 = data.point -> z[data.y1][data.x1];
	zoom(&data);
	isometric(&data.x, &data.y, z);
	isometric(&data.x1, &data.y1, z1);
	err = abs(data.x1 - data.x) - abs(data.y1 - data.y);
	while (!(data.x == data.x1 && data.y == data.y1)
		&& (data.x < 1920 && data.y < 1080) && data.y > 0 && data.x > 0)
	{
		mlx_put_pixel(data.point -> img, data.x, data.y, data.point -> color);
		if (err > 0)
		{
			err -= abs(data.y1 - data.y);
			data.x += get_steep_sx(&data.x, &data.x1, data.point);
		}
		else
		{
			err += abs(data.x1 - data.x);
			data.y += get_steep_sy(&data.y, &data.y1, data.point);
		}
	}
}

t_coords	*get_coords(t_point *point)
{
	t_coords	*coords;
	int			j;
	int			i;

	i = 0;
	j = 0;
	coords = (t_coords *)malloc(sizeof(t_coords) * point->height);
	if (!coords)
		return (NULL);
	while (j < point -> height)
	{
		coords[j].x = (int *)malloc(sizeof(int) * point->width);
		{
			while (i < point -> width)
			{
				coords[j].x[i] = i;
				i++;
			}
		}
		j++;
	}
	return (coords);
}

void	drawline(t_point *point)
{
	int		x;
	int		y;
	t_data	data;

	y = 0;
	while (y < point -> height)
	{
		x = 0;
		while (x < point -> width)
		{
			if (x < point -> width - 1)
			{
				data = (t_data){point, x, y, x + 1, y};
				wu_algo(data);
			}
			if (y < point -> height - 1)
			{
				data = (t_data){point, x, y, x, y + 1};
				wu_algo(data);
			}
			x++;
		}
		y++;
	}
}

void	zoom(t_data *data)
{
	data->x *= data->point->zoom;
	data->y1 *= data->point->zoom;
	data->x1 *= data->point->zoom;
	data->y1 *= data->point->zoom;
	// printf("%i\n", data -> x);
}

	/* cavalier(&x, &y, z);
	cavalier(&x1, &y1, z1); */
/* 	point -> alpha = get_angle(x, y, x1, y1, z, z1);
	point -> beta = get_angle(x, y, x1, y1, z, z1);
	point -> gamma = get_angle(x, y, x1, y1, z, z1); */
	/* get_rotation_x(&x, &z, point -> alpha);
	get_rotation_y(&x, &z, point -> beta);
	get_rotation_z(&x, &y, point -> gamma);
	get_rotation_x(&x1, &z1, point -> alpha);
	get_rotation_y(&x1, &z1, point -> beta);
	get_rotation_z(&x1, &y1, point -> gamma); */

/* 
	x += point -> shift_x;
	x1 += point -> shift_x;
	y += point -> shift_y;
	y1 += point -> shift_y; */

	/* if (z || z1)
	{
		if (z >= 0 && z <= 8)
			point -> color = 0x008800FF;
		if (z >= 21 && z < 24)
			point -> color = 0xFF770099;
		if (z >= 11)
			point -> color = 0x885500FF;
		else
		{
			if (z >= 9 && z <= 10)
				point -> color = 0x00940099;
		}
	} */

	