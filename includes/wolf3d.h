/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:39:37 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/30 11:39:39 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH		1500
# define WIN_HEIGHT		1300
# define NUM_TEXT		10
# define TEXT_W			64

# define KEY_UP				13
# define KEY_DOWN			1
# define KEY_LEFT			0
# define KEY_RIGHT			2
# define KEY_SHIFT			257
# define ESC				53
# define SPACE				49
# define NEXT				116
# define PREV				121

# define MSG(x) message(x)
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../miniLibX/mlx.h"
// # include <mlx.h>

typedef struct	s_scene
{
	int			height;
	int			start;
	int			end;
	int			t_n;
}				t_scene;

typedef struct	s_test
{
	int			t_num;
	float		wallx;
	int			t_x;
	int			t_y;
}				t_test;

typedef struct	s_ixy
{
	int			x;
	int			y;
}				t_ixy;

typedef struct	s_fxy
{
	float		x;
	float		y;
}				t_fxy;

typedef struct	s_color
{
	unsigned int color_1;
	unsigned int color_2;
	unsigned int color_3;
}				t_color;

typedef struct	s_ray
{
	t_fxy		pos;
	t_fxy		dir;
	t_fxy		delta;
	t_ixy		map;
	t_ixy		step;
	t_fxy		side;
	float		cam;
	float		dist;
	int			hit;
	int			hit_side;
}				t_ray;

typedef struct	s_player
{
	t_fxy		pos;
	t_fxy		dir;
	t_fxy		playn;
	float		speed_move;
	float		speed_turn;
	float		speed_shift;
	int			shift;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_player;

typedef struct	s_texture
{
	void		*file_ptr;
	char		*file_arr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct	s_img
{
	void		*img_ptr;
	char		*img_arr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			**map;
	int			color_sky;
	int			color_ground;
	int			map_height;
	int			map_weight;

	t_color		cside;
	t_img		img;
	t_texture	*texture;
	t_player	player;
	t_ray		ray;
	t_test		test;
	t_scene		scene;
}				t_mlx;

void			read_line(char *line, int **map, int y, t_mlx *mlx);
void			img_pixel(t_mlx *mlx, int x, int y, unsigned int c);
void			draw_line(t_mlx *mlx, int x, int start, int end);
void			img_set_pixel(int x, int y, t_mlx *mlx);
void			img_texture(t_mlx *mlx, int y, int x);
int				key_release(int index, t_mlx *mlx);
int				key_press(int index, t_mlx *mlx);
int				open_file(char *ar, t_mlx *mlx);
int				read_file(int fd, t_mlx *mlx);
void			read_pos(int fd, t_mlx *mlx);
void			set_textures_two(t_mlx *mlx);
void			init_ray(t_mlx *mlx, int x);
void			ray_draw(t_mlx *mlx, int x);
int				wolf_function(t_mlx *mlx);
void			change_color(t_mlx *mlx);
void			set_textures(t_mlx *mlx);
void			raycasting(t_mlx *mlx);
void			init_player(t_mlx *mlx);
void			move_right(t_mlx *mlx);
void			move_down(t_mlx *mlx);
void			move_left(t_mlx *mlx);
void			texture_n(t_mlx *mlx);
void			init_mlx(t_mlx *mlx);
void			img_init(t_mlx *mlx);
void			ray_step(t_mlx *mlx);
void			ray_dist(t_mlx *mlx);
void			get_text(t_mlx *mlx);
void			move_up(t_mlx *mlx);
void			move_up(t_mlx *mlx);
void			message(char *msg);
int				exit_x(void);

#endif
