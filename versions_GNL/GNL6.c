/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:32:21 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/29 13:00:37 by bboucher         ###   ########.fr       */
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

static int		is_line(t_list **li, char **line, int fd, int r)
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
				(*line) = ft_strdup(ft_strctrim(full_line, '\n'));
				ft_lstdelone(&(*li), &del_struct);
				return (r);
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

int				get_next_line(const int fd, char **line)
{
	int				rd;
	char			*buf;
	static t_list	*li;

	if (!line || fd < 0 || !(buf = ft_strnew(BUFF_SIZE))
		|| !((*line) = ft_strnew(0)))
		return (-1);
	rd = 1;
	if (!is_line(&li, line, fd, 1))
	{
		while (rd != 0 && !after_line(*line))
		{
			if ((rd = read(fd, buf, BUFF_SIZE)) < 0)
				return (-1);
			(*line) = ft_strjoin((*line), buf);
		}
		ft_lstadd_back(&li, ft_lstnew(new_s(fd, (*line)), sizeof(t_struct)));
		return (is_line(&li, line, fd, !buf[0] ? 0 : 1));
	}
	return (1);
}
