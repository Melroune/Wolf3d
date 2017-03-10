/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:33:37 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:33:43 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_mem;

	dst_mem = ft_strlen(dst);
	i = 0;
	if (size <= dst_mem)
		return (size + ft_strlen(src));
	while (dst_mem + i < (size - 1) && src[i] != '\0')
	{
		dst[i + dst_mem] = src[i];
		i++;
	}
	dst[i + dst_mem] = '\0';
	return (dst_mem + ft_strlen(src));
}
