/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:33:06 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:33:16 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strequ(const char *s1, const char *s2)
{
	unsigned int	ret;

	if (s1 && s2)
	{
		ret = ft_strcmp(s1, s2);
		if (ret == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
