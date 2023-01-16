/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:43:02 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/16 15:38:43 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#define WIDTH 600
#define HEIGHT 600

/* void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || (mlx_is_key_down(mlx, MLX_KEY_W)))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx, MLX_KEY_S)))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx, MLX_KEY_A)))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x += 5;
} */

/* void	rotation(t_point *point)
{
	int	x;
	int	y;
	int	z;

	x = point -> width;
	y = point -> height;
	z = point -> z[y][x];
	if (x > 0 && y > 0 && z > 0)
	{
		point -> angle += get_angle(x, x +1, y, y + 1);
		get_rotation_x(&x, &y, &z, point -> angle);
		get_rotation_y(&x, &y, &z, point -> angle);
		get_rotation_z(&x, &y, &z, point -> angle);
	}
	printf("x: %i, y: %i\n", x, y);
} */

void	clear_window(t_point *point)
{
	mlx_delete_image(point -> mlx, point -> img);
	point -> img = mlx_new_image(point -> mlx, 1920, 1080);
	mlx_image_to_window(point -> mlx, point -> img, 0, 0);
}

void	hook(void *param)
{
	t_point	*mlx;

	mlx = ((t_data *)param)->point;
	if (mlx_is_key_down(mlx -> mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx -> mlx);
}

void	key_hook(void *param)
{
	t_data	data;
	int		z;
	int		z1;

	data = *((t_data *) param);
	z = data.point -> z[data.y][data.x];
	z1 = data.point -> z[data.y1][data.x1];
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_UP))
		data.point -> shift_y -= 10;
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_DOWN))
		data.point -> shift_y += 10;
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_RIGHT))
		data.point -> shift_x += 10;
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_LEFT))
		data.point -> shift_x -= 10;
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_W))
		data.point -> zoom += 1;
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_S))
		data.point -> zoom -= 1;
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_A))
	{
	/* 	point -> alpha = get_angle(x, y, x1, y1, z, z1); */
		get_rotation_x(&data.x, &z, data.point -> alpha);
		data.point -> alpha += 0.05;
	}
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_F))
	{
	/* 	point -> alpha = get_angle(x, y, x1, y1, z, z1); */
		get_rotation_x(&data.x, &z, data.point -> alpha);
		data.point -> alpha -= 0.05;
	}
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_Q))
	{
	/* 	point -> beta = get_angle(x, y, x1, y1, z, z1); */
		get_rotation_y(&data.x, &z, data.point -> beta);
		data.point -> beta += 0.05;
	}
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_G))
	{
	/* 	point -> beta = get_angle(x, y, x1, y1, z, z1); */
		get_rotation_y(&data.x, &z, data.point -> beta);
		data.point -> beta -= 0.05;
	}
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_E))
	{
/* 		point -> gamma = get_angle(x, y, x1, y1, z, z1); */
		get_rotation_z(&data.x, &data.y, data.point -> gamma);
		data.point -> gamma += 0.05;
	}
	if (mlx_is_key_down(data.point -> mlx, MLX_KEY_H))
	{
/* 		point -> gamma = get_angle(x, y, x1, y1, z, z1); */
		get_rotation_z(&data.x, &data.y, data.point -> gamma);
		data.point -> gamma -= 0.05;
	}
	clear_window(data.point);
	drawline(data.point);
}

int	main(int argc, char **args)
{
	t_data		data;
	int			x;
	int			y;
/* 	t_coords	*coords;
	int			k = 0;
	int 		j = 0;
 */
	if (argc > 2)
		return (0);
	data.point = malloc(sizeof(*(data.point)));
	get_matrix(args[1], data.point);
	x = data.point->width;
	y = data.point->height;
	printf("%d\n", data.point->z[y-1][x-1]);
	/* coords = get_coords(&point);
	while (k < y)
	{
		j = 0;
		while (j < x)
		{
			coords[k].x[j] = j;
			j++;
		}
		k++;
	} */
	data.point->mlx = mlx_init(1920, 1080, "FDF", true);
	if (!data.point->mlx)
		exit(EXIT_FAILURE);
	data.point->img = mlx_new_image(data.point->mlx, 1920, 1080);
	data.point->shift_x = 300;
	data.point->shift_y = 300;
	drawline(data.point);
	mlx_image_to_window(data.point->mlx, data.point->img, 0, 0);
	mlx_loop_hook(data.point->mlx, &hook, &data);
	mlx_loop_hook(data.point->mlx, &key_hook, &data);
	mlx_loop(data.point->mlx);
	mlx_delete_image(data.point->mlx, data.point->img);
	mlx_terminate(data.point->mlx);
	return (EXIT_SUCCESS);
}

/* 640, 480, "FDF", true */