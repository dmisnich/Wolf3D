/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:45:19 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/26 12:45:21 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT,
	"WOLF3D - dmisnich");
	mlx->color_sky = 0x000000;
	mlx->color_ground = 0x646464;
	mlx->img.img_ptr = NULL;
	mlx->map_height = 0;
	mlx->map_weight = 0;
}

void		img_init(t_mlx *mlx)
{
	if (mlx->img.img_ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img_ptr);
		mlx->img.img_ptr = NULL;
	}
	else
	{
		mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
		mlx->img.img_arr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
		&mlx->img.size_line, &mlx->img.endian);
	}
}

void		init_player(t_mlx *mlx)
{
	mlx->player.speed_move = 0.08;
	mlx->player.speed_turn = 0.045;
	mlx->player.speed_shift = 0.13;
	mlx->player.pos.x = 0;
	mlx->player.pos.y = 0;
	mlx->player.dir.x = -1;
	mlx->player.dir.y = 0;
	mlx->player.playn.x = 0;
	mlx->player.playn.y = 0.66;
	mlx->player.up = 0;
	mlx->player.down = 0;
	mlx->player.left = 0;
	mlx->player.right = 0;
	mlx->player.shift = 0;
}

void		init_ray(t_mlx *mlx, int x)
{
	mlx->ray.cam = 2 * x / (float)WIN_WIDTH - 1;
	mlx->ray.dir.x = mlx->player.dir.x + mlx->player.playn.x * mlx->ray.cam;
	mlx->ray.dir.y = mlx->player.dir.y + mlx->player.playn.y * mlx->ray.cam;
	mlx->ray.map.x = (int)mlx->ray.pos.x;
	mlx->ray.map.y = (int)mlx->ray.pos.y;
	mlx->ray.delta.x = sqrt(1 + (mlx->ray.dir.y * mlx->ray.dir.y) /
		(mlx->ray.dir.x * mlx->ray.dir.x));
	mlx->ray.delta.y = sqrt(1 + (mlx->ray.dir.x * mlx->ray.dir.x) /
		(mlx->ray.dir.y * mlx->ray.dir.y));
	mlx->ray.hit = 0;
	mlx->ray.hit_side = 0;
}
