/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:38:50 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:38:54 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	k;
	char			*ret;

	i = start;
	k = 0;
	ret = (char*)ft_memalloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (NULL);
	while (i < start + len)
	{
		ret[k] = s[i];
		i++;
		k++;
	}
	ret[k] = '\0';
	return (ret);
}
