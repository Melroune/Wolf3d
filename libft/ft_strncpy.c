/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:34:56 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:35:00 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t c;

	c = 0;
	while (c < n && src[c] != '\0')
	{
		dst[c] = src[c];
		c++;
	}
	while (c < n)
	{
		dst[c] = '\0';
		c++;
	}
	return (dst);
}
