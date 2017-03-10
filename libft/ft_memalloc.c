/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:30:16 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:30:21 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if (size == 0)
		return (0);
	else
	{
		mem = (void *)malloc(size);
		if (mem == NULL)
			return (NULL);
		ft_bzero(mem, size);
		return (mem);
	}
}
