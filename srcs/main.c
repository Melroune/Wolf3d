/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:40:46 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 16:40:52 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	diry(t_env *e)
{
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->x = x;
		init_ray(e);
		if (e->raydirx < 0)
		{
			e->stepx = -1;
			e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
		}
		else
		{
			e->stepx = 1;
			e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
		}
		diry(e);
		dda(e);
		height_calc(e);
		if (e->map[e->mapy][e->mapx] == '2' && y <= e->yend && y >= e->ystart)
			e->map[e->mapy][e->mapx] = '0';
	}
	expose_hook(e);
	return (y);
}

void	close_map(t_env *e, int fd, char **map)
{
	close(fd);
	e->map = map;
	print_map(e);
}

void	get_map(t_env *e)
{
	int		fd;
	int		nbl;
	char	**map;
	char	*line;
	int		i;

	nbl = 0;
	i = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbl++;
		free(line);
	}
	close(fd);
	map = (char **)malloc(sizeof(char *) * (nbl + 1));
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map[i] = NULL;
	close_map(e, fd, map);
}

int		main(void)
{
	t_env		e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Wolf3D");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.str = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.endian));
	get_map(&e);
	init_player(&e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
