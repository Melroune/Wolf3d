/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:38:40 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:38:45 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int k;

	i = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			k = i;
			while (s1[i] && s2[j] && s1[k] == s2[j])
			{
				k++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
