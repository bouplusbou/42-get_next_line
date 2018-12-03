/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:35:20 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/03 09:23:25 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/////////////////////////////////////////////////////////////suppr
#include <stdio.h>

#include "get_next_line.h"

/*
   void	read_lst(t_list *li)
   {
   while (li)
   {
   printf("fd: %zu\n", li->content_size);
   printf("content: %s\n", li->content);
   li = li->next;
   }
   }
*/

t_list	*find_or_create_link(t_list **li, size_t fd)
{
	if (*li)
	{
		if ((*li)->content_size == fd)
		{
//			printf("good %zu\n", fd);	
			return (*li);
		}
		if ((*li)->next == NULL)
		{
			(*li)->next = ft_lstnew(NULL, 0);
			(*li)->next->content_size = fd;
			return ((*li)->next);
		}
		else
			return (find_or_create_link(&(*li)->next, fd));
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

int		get_one_line(t_list **link, char **line)
{
	char	*leftover;
	char	*one_line;

	if (ft_strchr((*link)->content, '\n'))
	{
//		printf("++into the first if get_one_line++\n");
		one_line = (*link)->content;
//		printf("one_line: %s\n", one_line);
		leftover = (ft_strchr(one_line, '\n') + 1);
//		printf("leftover: %s\n", leftover);
		leftover[-1] = '\0';
		*line = ft_strdup(one_line);
//		printf("*line: %s\n", *line);
		(*link)->content = ft_strdup(leftover);
//		printf("(*link)->content: %s\n", (*link)->content);
		if (ft_strequ((*link)->content, ""))
			delete_link(li, (*link)->content_size);
		return (1);
	}
	else if (ft_strequ((*link)->content, ""))
	{
//		printf("++ELSIF get_one_line++\n");
		ft_strclr(*line);
		delete_link(li, (*link)->content_size);
		return (0);
	}
//	printf("++ELSE get_one_line++\n");
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

//	printf("\n\n!!!start the function!!!\n");
	if (fd < 0 || !line || !(buf = ft_strnew(BUFF_SIZE))
		|| (rd = read(fd, buf, 0)) < 0)
		return (-1);
	link = find_or_create_link(&li, fd);
	if (!link || (!(link->content) && !(link->content = ft_strnew(0))))
		return (-1);
//	printf("link->content_size: %zu\n", link->content_size);
	while (!ft_strchr(link->content, '\n')
			&& (rd = read(fd, buf, BUFF_SIZE) > 0))
	{
//		printf("--into the read loop--\n");
//		printf("buf: %s\n", buf);
		tmp = link->content;
		link->content = ft_strjoin(link->content, buf);
		ft_strclr(buf);
		free(tmp);
	}
	if (rd < 0)
		return (-1);
//	printf("*line: %s\n", *line);
//	printf("link->content: %s\n", link->content);
	ft_strdel(&buf);
	return (get_one_line(&link, line));
}
