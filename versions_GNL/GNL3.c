/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:32:21 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/28 10:15:10 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////////////////////////////////////////////////////////////////////suppr
#include <stdio.h>



#include "get_next_line.h"

static t_fd		*new_link(int fd)
{
	t_fd	*link;

	if (!(link = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	link->fd = fd;
	link->str = ft_strnew(0);
	link->next = NULL;
	return (link);
}

static void		del_link(t_fd **li, int fd, int return_val)
{
	t_fd	*before;
	t_fd	*tmp;

	before = *li;
	while 
	
	return (return_val);
}

static t_fd		find_link(t_fd *li, int fd)
{
	while (li)
	{
		if (li->fd == fd)
			return (link);
		if (li->next == NULL)
			li->next = new_link(fd);
		li = li->next;
	}
	li = new_link(fd);
	return (li);
}

int				get_next_line(const int fd, char **line)
{
	int				rd;
	char			*buf;
	char			*tmp;
	t_fd			*link;
	static t_fd		*li;

	if (!line || fd < 0 || !(buf = ft_strnew(BUFF_SIZE)))
		|| !(link = find_link(li, fd)) || !(link->str = ft_strnew(0))
		return (-1)
	while (!ft_strchr(link->str, '\n') && (rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = link->str;
		link->str = ft_strjoin(link->str, buf);
		free(tmp);
	}
	free(buf);
	if ((rd == 0 && ft_strcmp(link->str, "\0")) || rd < 0)
		return (del_link(&li, fd, rd < 0 ? -1 : 0));
	return (rd);
}
