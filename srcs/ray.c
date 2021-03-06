/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:41:20 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 16:41:39 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			init_ray(t_env *e)
{
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->camerax = 2 * (double)e->x / (double)WIDTH - 1;
	e->raydirx = e->dirx + e->planx * e->camerax;
	e->raydiry = e->diry + e->plany * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry) /
		(e->raydirx * e->raydirx));
	e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx) /
		(e->raydiry * e->raydiry));
	e->hit = 0;
}

void			dda_again(t_env *e)
{
	if (e->side == 0 || e->side == 1)
		e->perpwalldist = fabs((e->mapx - e->rayposx + (1 - e->stepx) / 2)
			/ e->raydirx);
	else
		e->perpwalldist = fabs((e->mapy - e->rayposy + (1 - e->stepy) / 2)
			/ e->raydiry);
}

void			dda(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			if (e->stepx < 0)
				e->side = 0;
			else
				e->side = 1;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			if (e->stepy < 0)
				e->side = 2;
			else
				e->side = 3;
		}
		if (e->map[e->mapy][e->mapx] != '0')
			e->hit = 1;
	}
	dda_again(e);
}

void			raycasting_again(t_env *e)
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

void			raycasting(t_env *e)
{
	e->x = 0;
	while (e->x < WIDTH)
	{
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
		raycasting_again(e);
		dda(e);
		height_calc(e);
		draw(e);
		e->x++;
	}
}
