/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:58:48 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/20 09:58:50 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	init_player(&mlx);
	open_file(argv[1], &mlx);
	init_mlx(&mlx);
	system("afplay ./music/bal_satany.mp3&");
	set_textures(&mlx);
	img_init(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 3, 0, key_release, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_x, &mlx);
	mlx_loop_hook(mlx.mlx, wolf_function, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
