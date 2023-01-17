/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:42:23 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/17 12:33:15 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../libft/libft.h" 
#include "stdio.h"

void	wu_algo(t_point *point, int *begin, int *end)
{
	int			z;
	int			z1;

	z = point -> z[begin[1]][begin[0]];
	z1 = point -> z[end[1]][end[0]];
	zoom(point, begin, end);
	isometric(&begin[0], &begin[1], z);
	isometric(&end[0], &end[1], z1);
	shift(point, begin, end);
	color_z(point, z, z1);
	draw_pix(point, begin, end);
}

void	drawline(t_point *point)
{
	int		x;
	int		y;

	y = 0;
	while (y < point -> height)
	{
		x = 0;
		while (x < point -> width)
		{
			if (x < point -> width - 1)
			{
				point -> x = x;
				point -> x1 = x + 1;
				wu_algo(point, (int []){x, y}, (int []){x + 1, y});
			}
			if (y < point -> height - 1)
			{
				point -> y = y;
				point -> y1 = y + 1;
				wu_algo(point, (int []){x, y}, (int []){x, y + 1});
			}
			x++;
		}
		y++;
	}
}

void	draw_pix(t_point *point, int *begin, int *end)
{
	int	err;
	int	dx;
	int	dy;

	dx = abs(end[0] - begin[0]);
	dy = abs(end[1] - begin[1]);
	err = dx - dy;
	while (!(begin[0] == end[0] && begin[1] == end[1])
		&& (begin[0] < 1920 && begin[1] < 1080) && begin[1] > 0 && begin[0] > 0)
	{
		mlx_put_pixel(point -> img, begin[0], begin[1], point -> color);
		if (err > 0)
		{
			err -= dy;
			begin[0] += get_steep_sx(&begin[0], &end[0], point);
		}
		else
		{
			err += dx;
			begin[1] += get_steep_sy(&begin[1], &end[1], point);
		}
	}
}

void	color_z(t_point *point, int z, int z1)
{
	if (z || z1)
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
	}
}