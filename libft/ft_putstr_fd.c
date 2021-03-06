/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 17:32:10 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 17:32:15 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int c;

	c = 0;
	while (s[c] != '\0')
	{
		ft_putchar_fd(s[c], fd);
		c++;
	}
}
