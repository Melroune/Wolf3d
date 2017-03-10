/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:41:52 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 16:42:03 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				expose_hook(t_env *e)
{
	e->x = 0;
	while (e->x < WIDTH)
	{
		e->ystart = 0;
		e->yend = HEIGHT / 2;
		e->color = 0x69bbdb;
		draw(e);
		e->ystart = HEIGHT / 2;
		e->yend = HEIGHT;
		e->color = 0x77d877;
		draw(e);
		e->x++;
	}
	raycasting(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void			print_map(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			ft_putchar(e->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void			height_calc(t_env *e)
{
	e->lineheight = ABS((int)(HEIGHT / e->perpwalldist));
	e->ystart = (HEIGHT / 2) - (e->lineheight / 2);
	if (e->ystart < 0)
		e->ystart = 0;
	e->yend = (HEIGHT / 2) + (e->lineheight / 2);
	if (e->yend >= HEIGHT)
		e->yend = HEIGHT - 1;
	if (e->map[e->mapy][e->mapx] == '2')
		e->color = 0xf2f2ae;
	else
		e->color = 0x000033;
	if (e->side == 0 || e->side == 1)
		e->color <<= 1;
	if (e->map[e->mapy][e->mapx] == '1')
	{
		if (e->side == 0)
			e->color = 0xFF4040;
		else if (e->side == 1)
			e->color = 0xfbfb83;
		else if (e->side == 2)
			e->color = 0x71a0b0;
		else if (e->side == 3)
			e->color = 0x9f93e7;
	}
}

void			draw(t_env *e)
{
	int		i;

	while (e->ystart < e->yend)
	{
		i = e->x * (e->bpp / 8) + e->ystart * e->sl;
		e->str[i] = e->color;
		e->str[i + 1] = e->color >> 8;
		e->str[i + 2] = e->color >> 16;
		e->ystart++;
	}
}

void			init_player(t_env *e)
{
	e->posx = 4;
	e->posy = 4;
	e->dirx = -1;
	e->diry = 0;
	e->planx = 0;
	e->plany = 0.66;
}
