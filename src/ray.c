/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:57:40 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/05 11:57:41 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				raycasting(t_mlx *mlx)
{
	int				x;

	mlx->ray.pos.x = mlx->player.pos.x;
	mlx->ray.pos.y = mlx->player.pos.y;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		init_ray(mlx, x);
		ray_step(mlx);
		ray_dist(mlx);
		change_color(mlx);
		ray_draw(mlx, x);
	}
}

void				ray_step(t_mlx *mlx)
{
	if (mlx->ray.dir.x < 0)
	{
		mlx->ray.step.x = -1;
		mlx->ray.side.x = (mlx->ray.pos.x - (int)mlx->ray.pos.x) *
		mlx->ray.delta.x;
	}
	else
	{
		mlx->ray.step.x = 1;
		mlx->ray.side.x = ((int)mlx->ray.pos.x + 1 - mlx->ray.pos.x) *
		mlx->ray.delta.x;
	}
	if (mlx->ray.dir.y < 0)
	{
		mlx->ray.step.y = -1;
		mlx->ray.side.y = (mlx->ray.pos.y - (int)mlx->ray.pos.y) *
		mlx->ray.delta.y;
	}
	else
	{
		mlx->ray.step.y = 1;
		mlx->ray.side.y = ((int)mlx->ray.pos.y + 1 - mlx->ray.pos.y) *
		mlx->ray.delta.y;
	}
}

void				ray_dist(t_mlx *mlx)
{
	while (mlx->ray.hit == 0)
	{
		if (mlx->ray.side.x < mlx->ray.side.y)
		{
			mlx->ray.side.x += mlx->ray.delta.x;
			mlx->ray.map.x += mlx->ray.step.x;
			mlx->ray.hit_side = 0;
		}
		else
		{
			mlx->ray.side.y += mlx->ray.delta.y;
			mlx->ray.map.y += mlx->ray.step.y;
			mlx->ray.hit_side = 1;
		}
		if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] > 0)
		{
			mlx->ray.hit = 1;
			if (mlx->ray.hit_side == 0)
				mlx->ray.dist = (mlx->ray.map.x - mlx->ray.pos.x +
					(1 - mlx->ray.step.x) / 2) / mlx->ray.dir.x;
			else
				mlx->ray.dist = (mlx->ray.map.y - mlx->ray.pos.y +
					(1 - mlx->ray.step.y) / 2) / mlx->ray.dir.y;
		}
	}
}

void				change_color(t_mlx *mlx)
{
	if (mlx->player.pos.x < 23 && mlx->player.pos.y < 33)
		mlx->color_sky = 0x000000;
	else
		mlx->color_sky = 0xe7e7ff;
}

void				ray_draw(t_mlx *mlx, int x)
{
	mlx->scene.height = (int)(WIN_HEIGHT / mlx->ray.dist);
	mlx->scene.start = -mlx->scene.height / 2 + WIN_HEIGHT / 2;
	if (mlx->scene.start < 0)
		mlx->scene.start = 0;
	mlx->scene.end = mlx->scene.height / 2 + WIN_HEIGHT / 2;
	if (mlx->scene.end < 0)
		mlx->scene.end = 0;
	texture_n(mlx);
	mlx->test.t_num = mlx->map[mlx->ray.map.x][mlx->ray.map.y] - 1;
	if (mlx->ray.hit_side == 0)
		mlx->test.wallx = mlx->ray.pos.y + mlx->ray.dist * mlx->ray.dir.y;
	else
		mlx->test.wallx = mlx->ray.pos.x + mlx->ray.dist * mlx->ray.dir.x;
	mlx->test.wallx -= floor((mlx->test.wallx));
	mlx->test.t_x = (int)(mlx->test.wallx * (float)TEXT_W);
	if (mlx->ray.hit_side == 0 && mlx->ray.dir.x > 0)
		mlx->test.t_x = TEXT_W - mlx->test.t_x - 1;
	if (mlx->ray.hit_side == 1 && mlx->ray.dir.y < 0)
		mlx->test.t_x = TEXT_W - mlx->test.t_x - 1;
	draw_line(mlx, x, mlx->scene.start, mlx->scene.end);
}
