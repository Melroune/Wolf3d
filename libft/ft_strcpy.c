/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:32:44 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:32:49 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	c;

	c = 0;
	while (src[c] != '\0')
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
}