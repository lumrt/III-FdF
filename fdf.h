/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:28:29 by lumaret           #+#    #+#             */
/*   Updated: 2024/08/27 18:16:20 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define ESC 65307

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define PAGE_UP 65365
# define PAGE_DOWN 65366

# define ZOOM 61
# define DEZOOM 45

# define SPACE 32

# define W 119
# define A 97
# define S 115
# define D 100

# define BASE_SCALE 30

typedef struct s_fdf
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*addr;
	int		*map_size;
	int		bpp;
	int		ll;
	int		endian;
	int		win_width;
	int		win_height;
	int		scale;
	int		start_x;
	int		start_y;
	int		map_height;
	int		x;
	int		y;
	int		z;

}			t_fdf;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		err;
	int		x0;
	int		y0;
	int		sx;
	int		sy;
}			t_line;

int			get_arr_length(char *line, t_fdf *fdf);
int			draw(t_fdf *fdf);
int			*iso_proj(t_fdf *fdf, int x, int y, int z);
char		**init_parsing(t_fdf *fdf, char *file_name);
void		init_everything(char *map, t_fdf *fdf);
void		free_map(char **map);
void		free_splits(char ***splits, int size);
void		free_mlx(t_fdf *fdf);
void		redraw(t_fdf *fdf);
int			*map_checker(t_fdf *fdf, char **map);
void		set(t_fdf *fdf);
int			get_x(t_fdf *fdf, int x);
int			get_y(t_fdf *fdf, int y, int scale);
void		draw_vertical(t_fdf *fdf);
void		draw_horizontal(t_fdf *fdf, char **split, int y1);
void		iso_movement(t_fdf *fdf, int direction);
void		zoom_handler(t_fdf *fdf, int direction);
void		change_z(t_fdf *fdf, int key);
void		malloc_exit(t_fdf *fdf);
void		drawline(t_fdf *fdf, int *start, int *end);

#endif
