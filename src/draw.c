/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:20:39 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/15 17:20:41 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				draw_line(t_mlx *mlx, int x, int start, int end)
{
	int				i;

	i = -1;
	while (++i < start)
		img_pixel(mlx, x, i, mlx->color_sky);
	i--;
	while (++i <= end && i < WIN_WIDTH)
		img_texture(mlx, i, x);
	i--;
	while (++i < WIN_HEIGHT)
		img_pixel(mlx, x, i, mlx->color_ground);
}

void				img_texture(t_mlx *mlx, int y, int x)
{
	int				i;

	get_text(mlx);
	i = y * 256 - WIN_HEIGHT * 128 + mlx->scene.height * 128;
	mlx->test.t_y = ((i * TEXT_W / mlx->scene.height) / 256);
	mlx->img.img_arr[4 * (WIN_WIDTH * y + x)] = mlx->texture
	[mlx->scene.t_n].file_arr[(4 * (TEXT_W * mlx->test.t_y + mlx->test.t_x))];
	mlx->img.img_arr[4 * (WIN_WIDTH * y + x) + 1] = mlx->texture
	[mlx->scene.t_n].file_arr[(4 * (TEXT_W * mlx->test.t_y +
		mlx->test.t_x)) + 1];
	mlx->img.img_arr[4 * (WIN_WIDTH * y + x) + 2] = mlx->texture
	[mlx->scene.t_n].file_arr[(4 * (TEXT_W * mlx->test.t_y +
		mlx->test.t_x)) + 2];
}

void				img_pixel(t_mlx *mlx, int x, int y, unsigned int c)
{
	int				i;

	i = (x * 4) + (y * mlx->img.size_line);
	mlx->img.img_arr[i++] = c;
	mlx->img.img_arr[i++] = c >> 8;
	mlx->img.img_arr[i] = c >> 16;
}

void				get_text(t_mlx *mlx)
{
	if (mlx->ray.hit_side == 1)
	{
		if ((mlx->ray.step.x == -1 && mlx->ray.step.y == -1) ||
			(mlx->ray.step.x == 1 && mlx->ray.step.y == -1))
		{
			if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 6)
				mlx->scene.t_n = 0;
		}
		if ((mlx->ray.step.x == -1 && mlx->ray.step.y == 1) ||
			(mlx->ray.step.x == 1 && mlx->ray.step.y == 1))
		{
			if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 6)
				mlx->scene.t_n = 0;
		}
		else
		{
			if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 6)
				mlx->scene.t_n = 9;
		}
	}
}
