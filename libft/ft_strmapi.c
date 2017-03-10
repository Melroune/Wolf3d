/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:34:37 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:34:42 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	int		i;
	char	*dest;

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
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
