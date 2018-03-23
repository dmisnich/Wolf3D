/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:13:56 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/15 17:13:58 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_up(t_mlx *mlx)
{
	if (mlx->player.shift)
	{
		if (mlx->map[(int)(mlx->player.pos.x + mlx->player.dir.x *
		mlx->player.speed_shift)][(int)mlx->player.pos.y] == 0)
			mlx->player.pos.x += mlx->player.dir.x * mlx->player.speed_shift;
		if (mlx->map[(int)mlx->player.pos.x][(int)(mlx->player.pos.y +
		mlx->player.dir.y * mlx->player.speed_shift)] == 0)
			mlx->player.pos.y += mlx->player.dir.y * mlx->player.speed_shift;
	}
	else
	{
		if (mlx->map[(int)(mlx->player.pos.x + mlx->player.dir.x *
		mlx->player.speed_move)][(int)mlx->player.pos.y] == 0)
			mlx->player.pos.x += mlx->player.dir.x * mlx->player.speed_move;
		if (mlx->map[(int)mlx->player.pos.x][(int)(mlx->player.pos.y +
		mlx->player.dir.y * mlx->player.speed_move)] == 0)
			mlx->player.pos.y += mlx->player.dir.y * mlx->player.speed_move;
	}
}

void		move_down(t_mlx *mlx)
{
	if (mlx->map[(int)(mlx->player.pos.x - mlx->player.dir.x *
	mlx->player.speed_move)][(int)mlx->player.pos.y] == 0)
		mlx->player.pos.x -= mlx->player.dir.x * mlx->player.speed_move;
	if (mlx->map[(int)mlx->player.pos.x][(int)(mlx->player.pos.y -
	mlx->player.dir.y * mlx->player.speed_move)] == 0)
		mlx->player.pos.y -= mlx->player.dir.y * mlx->player.speed_move;
}

void		move_left(t_mlx *mlx)
{
	t_fxy	tmp;

	tmp.x = mlx->player.dir.x;
	mlx->player.dir.x = mlx->player.dir.x * cos(mlx->player.speed_turn) -
	mlx->player.dir.y * sin(mlx->player.speed_turn);
	mlx->player.dir.y = tmp.x * sin(mlx->player.speed_turn) +
	mlx->player.dir.y * cos(mlx->player.speed_turn);
	tmp.x = mlx->player.playn.x;
	mlx->player.playn.x = mlx->player.playn.x * cos(mlx->player.speed_turn) -
	mlx->player.playn.y * sin(mlx->player.speed_turn);
	mlx->player.playn.y = tmp.x * sin(mlx->player.speed_turn) +
	mlx->player.playn.y * cos(mlx->player.speed_turn);
}

void		move_right(t_mlx *mlx)
{
	t_fxy	tmp;

	tmp.x = mlx->player.dir.x;
	mlx->player.dir.x = mlx->player.dir.x * cos(-mlx->player.speed_turn) -
	mlx->player.dir.y * sin(-mlx->player.speed_turn);
	mlx->player.dir.y = tmp.x * sin(-mlx->player.speed_turn) +
	mlx->player.dir.y * cos(-mlx->player.speed_turn);
	tmp.x = mlx->player.playn.x;
	mlx->player.playn.x = mlx->player.playn.x * cos(-mlx->player.speed_turn) -
	mlx->player.playn.y * sin(-mlx->player.speed_turn);
	mlx->player.playn.y = tmp.x * sin(-mlx->player.speed_turn) +
	mlx->player.playn.y * cos(-mlx->player.speed_turn);
}
