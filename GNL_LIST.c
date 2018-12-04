/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:35:20 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/03 16:50:34 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_or_create_link(t_list **li, size_t fd)
{
	if (*li)
	{
		if ((*li)->content_size == fd)
		{
			return (*li);
		}
		if ((*li)->next == NULL)
		{
			(*li)->next = ft_lstnew(NULL, 0);
			(*li)->next->content_size = fd;
			return ((*li)->next);
		}
		else
		{
			return (find_or_create_link(&(*li)->next, fd));
		}
	}
	*li = ft_lstnew(NULL, 0);
	(*li)->content_size = fd;
	return (*li);
}

void	delete_link(t_list **li, size_t fd)
{
	t_list	*tmp;
	t_list	*before;

	tmp = *li;
	while (tmp->next)
	{
		if ((tmp->next)->content_size == fd)
		{
			before = tmp;
			before->next = (tmp->next)->next;
			free(tmp->next);
			return ;
		}
		tmp = tmp->next;
	}
}

void	get_one_line(t_list **link, char **line, t_list **li)
{
	char	*leftover;
	char	*one_line;
	char	*tmp;

	one_line = (*link)->content;
	leftover = (ft_strchr(one_line, '\n') + 1);
	leftover[-1] = '\0';
	*line = ft_strdup(one_line);
	tmp = (*link)->content;
	(*link)->content = ft_strdup(leftover);
	if (ft_strequ((*link)->content, ""))
		delete_link(li, (*link)->content_size);
	free(tmp);
}

int		manage_link(t_list **link, char **line, t_list **li)
{
	if (ft_strchr((*link)->content, '\n'))
	{
		get_one_line(link, line, li);
		return (1);
	}
	else if (ft_strequ((*link)->content, ""))
	{
		ft_strclr(*line);
		delete_link(li, (*link)->content_size);
		return (0);
	}
	*line = ft_strdup((*link)->content);
	ft_strclr((*link)->content);
	delete_link(li, (*link)->content_size);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*li;
	t_list			*link;
	int				rd;
	char			*buf;
	char			*tmp;

	if (fd < 0 || !line || !(buf = ft_strnew(BUFF_SIZE))
		|| (rd = read(fd, buf, 0)) < 0)
		return (-1);
	link = find_or_create_link(&li, fd);
	if (!link || (!(link->content) && !(link->content = ft_strnew(0))))
		return (-1);
	while (!ft_strchr(link->content, '\n')
			&& (rd = read(fd, buf, BUFF_SIZE) > 0))
	{
		tmp = link->content;
		link->content = ft_strjoin(link->content, buf);
		ft_strclr(buf);
		free(tmp);
	}
	if (rd < 0)
		return (-1);
	ft_strdel(&buf);
	return (manage_link(&link, line, &li));
}
