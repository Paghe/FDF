/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:43:02 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/17 12:33:05 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 600
#define HEIGHT 600

void	clear_window(t_point *point)
{
	mlx_delete_image(point -> mlx, point -> img);
	point -> img = mlx_new_image(point -> mlx, 1920, 1080);
	mlx_image_to_window(point -> mlx, point -> img, 0, 0);
}

void	hook(void *param)
{
	t_point	*mlx;

	mlx = (t_point *)param;
	if (mlx_is_key_down(mlx -> mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx -> mlx);
}

void	key_hook(void *param)
{
	t_point	*point;

	point = (t_point *)param;
	if (mlx_is_key_down(point -> mlx, MLX_KEY_UP))
		point -> shift_y -= 10;
	if (mlx_is_key_down(point -> mlx, MLX_KEY_DOWN))
		point -> shift_y += 10;
	if (mlx_is_key_down(point -> mlx, MLX_KEY_RIGHT))
		point -> shift_x += 10;
	if (mlx_is_key_down(point -> mlx, MLX_KEY_LEFT))
		point -> shift_x -= 10;
	if (mlx_is_key_down(point -> mlx, MLX_KEY_W))
		point -> zoom += 1;
	if (mlx_is_key_down(point -> mlx, MLX_KEY_S))
		point -> zoom -= 1;
	clear_window(point);
	drawline(point);
}

int	main(int argc, char **args)
{
	t_point		point;

	if (argc > 2)
		return (0);
	get_matrix(args[1], &point);
	point.zoom = 2;
	point.mlx = mlx_init(1920, 1080, "FDF", true);
	if (!point.mlx)
		exit(EXIT_FAILURE);
	point.img = mlx_new_image(point.mlx, 1920, 1080);
	point.shift_x = 300;
	point.shift_y = 300;
	drawline(&point);
	mlx_image_to_window(point.mlx, point.img, 0, 0);
	mlx_loop_hook(point.mlx, &hook, &point);
	mlx_loop_hook(point.mlx, &key_hook, &point);
	mlx_loop(point.mlx);
	mlx_delete_image(point.mlx, point.img);
	mlx_terminate(point.mlx);
	return (EXIT_SUCCESS);
}
