/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:40:32 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 16:40:36 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		left(e);
	else if (keycode == 124)
		right(e);
	else if (keycode == 126)
		up(e);
	else if (keycode == 125)
		down(e);
	expose_hook(e);
	return (keycode);
}
