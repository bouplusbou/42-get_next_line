/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:32:21 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/28 08:16:38 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////////////////////////////////////////////////////////////////////suppr
#include <stdio.h>

#include "get_next_line.h"

static t_struct	*new_s(int fd, char *str)
{
	t_struct	*content;

	if (!(content = ft_memalloc(sizeof(t_struct*))))
		return (NULL);
	content->fd = fd;
	while (*str == '\n')
		str++;
	content->str = ft_strdup(str);
	return (content);
}

static void		del_struct(void *content, size_t size)
{
	(void)size;
	ft_strdel(&((t_struct*)content)->str);
	ft_memdel(&content);
}

static int		save_in_line(t_list **li, char **line, int fd)
{
	char	*full_line;
	char	*all;

	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			rd;
	char		*buf;
	static char	*tab[] = {NULL};

	if (fd < 0 || fd > !(buf = ft_strnew(BUFF_SIZE))
			|| !((*line) = ft_strnew(BUFF_SIZE)))
		return (-1);
	{
		if ((rd = read(fd, buf, BUFF_SIZE)) && rd == -1) 
		*line = ft_strjoin((*line), buf);
	}
	return (1);
}
