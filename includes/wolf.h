/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:39:26 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 16:39:33 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# define WIDTH 1000
# define HEIGHT 800
# define ABS(x) ((x >= 0) ? x : -(x))
# define MAP_FILE "./map.wolf"
# define GUN "../srcs/GUN.bmp"
# define MS 0.3
# define RS 0.3

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str;
	int			bpp;
	int			sl;
	int			endian;

	char		**map;

	int			mapx;
	int			mapy;

	int			x;

	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;

	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		camerax;

	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;

	int			lineheight;
	int			ystart;
	int			yend;

	int			color;

}				t_env;

void			raycasting(t_env *e);
void			left(t_env *e);
void			right(t_env *e);
void			down(t_env *e);
void			up(t_env *e);
void			draw(t_env *e);
void			init_ray(t_env *e);
void			dda(t_env *e);
void			height_calc(t_env *e);
int				expose_hook(t_env *e);
void			print_map(t_env *e);
void			raycasting_again(t_env *e);
void			dda_again(t_env *e);
int				key_hook(int keycode, t_env *e);
void			init_player(t_env *e);
#endif
