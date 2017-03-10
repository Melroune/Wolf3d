/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:31:31 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:31:37 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int c;

	c = 0;
	while (s[c] != '\0')
	{
		ft_putchar(s[c]);
		c++;
	}
	ft_putchar('\n');
}