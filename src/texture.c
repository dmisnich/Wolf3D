/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:18:11 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/15 17:18:12 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_textures(t_mlx *mlx)
{
	mlx->texture = (t_texture *)malloc(sizeof(t_texture) * NUM_TEXT);
	mlx->texture[0].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/redstone.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[0].file_arr = mlx_get_data_addr(mlx->texture[0].file_ptr,
	&mlx->texture[0].bpp, &mlx->texture[0].size_line, &mlx->texture[0].endian);
	mlx->texture[1].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/greystone.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[1].file_arr = mlx_get_data_addr(mlx->texture[1].file_ptr,
	&mlx->texture[1].bpp, &mlx->texture[1].size_line, &mlx->texture[1].endian);
	mlx->texture[2].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/bulestone.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[2].file_arr = mlx_get_data_addr(mlx->texture[2].file_ptr,
	&mlx->texture[2].bpp, &mlx->texture[2].size_line, &mlx->texture[2].endian);
	mlx->texture[3].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/eagle.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[3].file_arr = mlx_get_data_addr(mlx->texture[3].file_ptr,
	&mlx->texture[3].bpp, &mlx->texture[3].size_line, &mlx->texture[3].endian);
	mlx->texture[4].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/peterson.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[4].file_arr = mlx_get_data_addr(mlx->texture[4].file_ptr,
	&mlx->texture[4].bpp, &mlx->texture[4].size_line, &mlx->texture[4].endian);
	set_textures_two(mlx);
}

void	set_textures_two(t_mlx *mlx)
{
	mlx->texture[5].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/gitler.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[5].file_arr = mlx_get_data_addr(mlx->texture[5].file_ptr,
	&mlx->texture[5].bpp, &mlx->texture[5].size_line, &mlx->texture[5].endian);
	mlx->texture[6].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/orel.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[6].file_arr = mlx_get_data_addr(mlx->texture[6].file_ptr,
	&mlx->texture[6].bpp, &mlx->texture[6].size_line, &mlx->texture[6].endian);
	mlx->texture[7].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/svastika.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[7].file_arr = mlx_get_data_addr(mlx->texture[7].file_ptr,
	&mlx->texture[7].bpp, &mlx->texture[7].size_line, &mlx->texture[7].endian);
	mlx->texture[8].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/fon.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[8].file_arr = mlx_get_data_addr(mlx->texture[8].file_ptr,
	&mlx->texture[8].bpp, &mlx->texture[8].size_line, &mlx->texture[8].endian);
	mlx->texture[9].file_ptr = mlx_xpm_file_to_image(mlx->mlx,
		"textures/flag.xpm", &mlx->texture->width, &mlx->texture->height);
	mlx->texture[9].file_arr = mlx_get_data_addr(mlx->texture[9].file_ptr,
	&mlx->texture[9].bpp, &mlx->texture[9].size_line, &mlx->texture[9].endian);
}

void	texture_n(t_mlx *mlx)
{
	if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 1)
		mlx->scene.t_n = 0;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 2)
		mlx->scene.t_n = 1;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 3)
		mlx->scene.t_n = 2;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 4)
		mlx->scene.t_n = 3;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 5)
		mlx->scene.t_n = 4;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 6)
		mlx->scene.t_n = 5;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 7)
		mlx->scene.t_n = 6;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 8)
		mlx->scene.t_n = 7;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 9)
		mlx->scene.t_n = 8;
	else if (mlx->map[mlx->ray.map.x][mlx->ray.map.y] == 10)
		mlx->scene.t_n = 9;
}
