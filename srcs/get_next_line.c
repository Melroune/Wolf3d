/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 16:40:18 by akerkeb           #+#    #+#             */
/*   Updated: 2015/06/26 16:40:22 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_strlen2(char *s)
{
	int		c;

	c = 0;
	while (s[c])
	{
		if (s[c] == '\n')
			return (c);
		c++;
	}
	return (c);
}

int			get_next_line(int const fd, char **line)
{
	static char	*mem = 0;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	int			i;

	while (!ft_strchr(mem, '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		mem = ft_strjoin(mem, buff);
		if (ret == 0 && !ft_strchr(mem, '\n'))
		{
			*line = mem;
			return (0);
		}
	}
	i = ft_strlen2(mem);
	if (mem[0] != '\n')
		*line = ft_strsub(mem, 0, i);
	else
		*line = ft_strsub(mem, 1, i);
	mem = mem + i + 1;
	return (1);
}
