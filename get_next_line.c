/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:35:20 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/29 16:00:15 by bboucher         ###   ########.fr       */
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
			printf("good %zu\n", fd);	
			return (*li);
		}
		if ((*li)->next == NULL)
		{
			(*li)->next = ft_lstnew(NULL, 0);
			(*li)->next->content_size = fd;
			return ((*li)->next);
		}
		else
			return (link_find_or_create(&(*li)->next, fd));
	}
	*li = ft_lstnew(NULL, 0);
	(*li)->content_size = fd;
	return (*li);
}

int		is_line(char *line)
{
	while (*line == '\n')
		line++;
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*li;
	t_list			*link;
	int				rd;
	char			*buf;

	if (fd < 0 || !line || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	link = find_or_create_link(&li, fd);
	while ((rd = 0) && !is_line(*line) && rd = read(fd, buf, BUFF_SIZE) > 0)
	{
		
	}
	return (0);
}
