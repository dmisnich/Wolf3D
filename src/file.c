/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:39:29 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/26 12:39:34 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			open_file(char *ar, t_mlx *mlx)
{
	int		fd;

	if ((fd = open(ar, O_RDONLY)) < 0)
		MSG("Error open");
	return (read_file(fd, mlx));
}

int			read_file(int fd, t_mlx *mlx)
{
	char	*line;
	int		**map;
	int		y;

	y = 0;
	read_pos(fd, mlx);
	map = (int **)malloc(sizeof(int *) * mlx->map_height);
	if (!map)
		MSG("Error malloc");
	while (get_next_line(fd, &line))
	{
		read_line(line, map, y, mlx);
		y++;
	}
	mlx->map = map;
	return (0);
}

void		read_line(char *line, int **map, int y, t_mlx *mlx)
{
	int		x;
	char	**split_line;

	x = 0;
	map[y] = (int *)malloc(sizeof(int *) * mlx->map_weight);
	split_line = ft_strsplit(line, ' ');
	free(line);
	while (split_line[x] != '\0')
	{
		map[y][x] = ft_atoi(split_line[x]);
		x++;
	}
	ft_free_arr(&split_line);
}

void		read_pos(int fd, t_mlx *mlx)
{
	char	*line;
	char	**line_split;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) < 0)
		MSG("Error GNL");
	line_split = ft_strsplit(line, ' ');
	free(line);
	while (line_split[i] != '\0')
		i++;
	if (i != 4)
		MSG("Error map");
	mlx->map_height = ft_atoi(line_split[0]);
	mlx->map_weight = ft_atoi(line_split[1]);
	mlx->player.pos.x = ft_atoi(line_split[2]) + 0.5;
	mlx->player.pos.y = ft_atoi(line_split[3]) + 0.5;
	ft_free_arr(&line_split);
}
