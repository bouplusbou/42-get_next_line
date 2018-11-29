/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:32:21 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/28 12:54:30 by bboucher         ###   ########.fr       */
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

static int		get_line(t_list **li, char **line, int fd, int len)
{
	char	*tmp;

	while (*li)
	{
		if (((t_struct*)(*li)->content)->fd == fd)
		{
			while ((*data)[len_l] && (*data)[len_l] != '\n')
				len_l++;
			if (((*data)[len_l]) == '\n')
			{
				*line = ft_strsub(*data, 0, len_l);
				tmp = *data;
				*data = ft_strdup(&(*data)[len_l + 1]);
				free(tmp);
				!(*data)[0] ? ft_lstdelone(&(*li), &del_struct) : 0;
			}
			else if (!((*data)[len_l]))
			{
				*line = ft_strdup(*data);
				ft_strdel(data);
			}
		}
		*li = (*li)->next;
	}
	return (1);
}

static t_list	*find_fd(t_list **li, int fd)
{
	t_list	*tmp;

	tmp = *li;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	int				rd;
	char			*buf;
	t_list			*li_fd;
	static t_list	*li;

	if (fd < 0 || !line || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	li_fd = find_fd(&li, fd);
	if (li_fd == NULL)
	{
		while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
		{
			*line = ft_strjoin((*line), buf);
		}
		ft_lstadd_back(&li, ft_lstnew(new_s(fd, (*line)), sizeof(t_struct)));
		free(buf);
	}
	if (rd < 0 || (rd == 0 && li_fd->str[0] == '\0'))
		return (rd < 0 ? -1 : 0);
	return (get_line(&li, line, fd, 0));
}
