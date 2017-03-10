/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:33:50 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:33:54 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;
	int		c;

	if (s == NULL)
		return (NULL);
	if (s && f)
	{
		c = ft_strlen(s);
		dest = ft_strnew(c + 1);
		i = 0;
		if (f == NULL)
			return (ft_strdup(s));
		while (i < c)
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
