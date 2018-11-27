/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:32:21 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/27 09:33:52 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char		*after_line(char *str)
{
	while (*str == '\n')
		str++;
	while (*str)
	{
		if (*str == '\n')
			return (str + 1);
		str++;
	}
	return (NULL);
}

static void		del_struct(void *content, size_t size)
{
	(void)size;
	ft_strdel(&((t_struct*)content)->str);
	ft_memdel(&content);
}

static int		is_line(t_list **li, char **line, char **big_buf, int fd)
{
	char	*full_line;
	char	*all;

	while (*li)
	{
		if (((t_struct*)(*li)->content)->fd == fd)
		{
			full_line = ((t_struct*)(*li)->content)->str;
			all = after_line(full_line);
			if (!all)
			{
				(*big_buf) = ft_strdup(ft_strctrim(full_line, '\n'));
				ft_lstdelone(&(*li), &del_struct);
				return (0);
			}
			all[-1] = '\0';
			*line = ft_strdup(ft_strctrim(full_line, '\n'));
			((t_struct*)(*li)->content)->str = ft_strdup(all);
			return (1);
		}
		*li = (*li)->next;
	}
	return (0);
}
//////////////////////////////////////////////////////////////////////////////////////////////suppr
#include <stdio.h>

int				get_next_line(const int fd, char **line)
{
	int				rd;
	char			*buf;
	char			*big_buf;
	static t_list	*li;

	if (fd < 0 || !(buf = ft_strnew(BUFF_SIZE))
		|| !(big_buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!is_line(&li, line, &big_buf, fd))
	{
		while (!after_line(big_buf) && rd != 0)
		{
			if ((rd = read(fd, buf, BUFF_SIZE)) && rd == -1)
				return (-1);
			big_buf = ft_strjoin(big_buf, buf);
		}
//		printf("big_buf: %s\n", big_buf);
		!li ? li = ft_lstnew(new_s(fd, big_buf), sizeof(t_struct))
			: ft_lstadd(&li, ft_lstnew(new_s(fd, big_buf), sizeof(t_struct)));
		free(big_buf);
		is_line(&li, line, &buf, fd);
		free(buf);
		if (rd == 0)
			return (0);
	}
	return (1);
}
