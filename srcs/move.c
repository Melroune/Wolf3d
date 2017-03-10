/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:41:04 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 16:41:10 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	left(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(RS) - e->diry * sin(RS);
	e->diry = olddirx * sin(RS) + e->diry * cos(RS);
	oldplanex = e->planx;
	e->planx = e->planx * cos(RS) - e->plany * sin(RS);
	e->plany = oldplanex * sin(RS) + e->plany * cos(RS);
}

void	right(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(-RS) - e->diry * sin(-RS);
	e->diry = olddirx * sin(-RS) + e->diry * cos(-RS);
	oldplanex = e->planx;
	e->planx = e->planx * cos(-RS) - e->plany * sin(-RS);
	e->plany = oldplanex * sin(-RS) + e->plany * cos(-RS);
}

void	down(t_env *e)
{
	if (e->map[(int)(e->posy - e->diry * MS)][(int)(e->posx)] == '0')
		e->posy -= e->diry * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx - e->dirx * MS)] == '0')
		e->posx -= e->dirx * MS;
}

void	up(t_env *e)
{
	if (e->map[(int)(e->posy + e->diry * MS)][(int)(e->posx)] == '0')
		e->posy += e->diry * MS;
	if (e->map[(int)(e->posy)][(int)(e->posx + e->dirx * MS)] == '0')
		e->posx += e->dirx * MS;
}
