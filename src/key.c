/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:15:06 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/15 17:15:07 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			wolf_function(t_mlx *mlx)
{
	if (mlx->player.up)
		move_up(mlx);
	if (mlx->player.down)
		move_down(mlx);
	if (mlx->player.left)
		move_left(mlx);
	if (mlx->player.right)
		move_right(mlx);
	raycasting(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int			key_press(int index, t_mlx *mlx)
{
	if (index == KEY_UP)
		mlx->player.up = 1;
	if (index == KEY_DOWN)
		mlx->player.down = 1;
	if (index == KEY_RIGHT)
		mlx->player.right = 1;
	if (index == KEY_LEFT)
		mlx->player.left = 1;
	if (index == KEY_SHIFT)
		mlx->player.shift = 1;
	if (index == NEXT)
	{
		system("pkill afplay");
		system("afplay ./music/sv.mp3&");
	}
	if (index == PREV)
	{
		system("pkill afplay");
		system("afplay ./music/bal_satany.mp3&");
	}
	if (index == ESC)
		exit_x();
	return (0);
}

int			key_release(int index, t_mlx *mlx)
{
	if (index == KEY_UP)
		mlx->player.up = 0;
	if (index == KEY_DOWN)
		mlx->player.down = 0;
	if (index == KEY_RIGHT)
		mlx->player.right = 0;
	if (index == KEY_LEFT)
		mlx->player.left = 0;
	if (index == KEY_SHIFT)
		mlx->player.shift = 0;
	return (0);
}
