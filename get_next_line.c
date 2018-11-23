/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:17:35 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/23 13:45:49 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	read_list(t_list *begin_list)
{
	while (begin_list)
	{
		printf("loop readlist:\n");
		ft_putendl(((t_struct*)begin_list->content)->str);
		ft_putnbr(((t_struct*)begin_list->content)->fd);
		ft_putchar('\n');
		ft_putnbr(((t_struct*)begin_list->content)->leftover);
		ft_putchar('\n');
		ft_putchar('\n');
		begin_list = begin_list->next;
	}
}

t_struct	*new_struct(int fd, int leftover, char *str)
{
	t_struct	*content;

	content = ft_memalloc(sizeof(content));
	content->fd = fd;
	content->leftover = leftover;
	content->str = ft_strdup(str);
	return (content);
}

int		save_del(int fd, char **line, t_list **begin_list)
{
	t_list	*tmp;
	
	while (*begin_list)
	{
		if (((t_struct*)(*begin_list)->content)->fd == fd)
		{
			tmp = *begin_list;
			*line = ft_strdup(((t_struct*)(*begin_list)->content)->str);
			*begin_list = (*begin_list)->next;
			tmp->next = NULL;
			return (1);
		}
		*begin_list = (*begin_list)->next;
	}
	return (0);
}

void	create_lines(char *leftover_str, int fd, t_list **begin_list)
{
	int			rd;
	int			i;
	int			leftover;
	char		*buf;
	char		*buf_tmp;
	char		**tab;
	t_list		*new_list;
	t_struct	*content;
	
	buf = ft_strnew(BUFF_SIZE);
	rd = read(fd, buf, BUFF_SIZE);
	while (ft_strequ(buf, "\n"))
		rd = read(fd, buf, BUFF_SIZE);
	if (rd == 0)
	{
		buf = NULL;
		return ;
	}
	buf_tmp = ft_strnew(BUFF_SIZE); // si pas de bn
	while (!ft_strchr(buf, '\n'))
	{
		rd = read(fd, buf_tmp, BUFF_SIZE);	
		buf = ft_strjoin(buf, buf_tmp);
	}
	if (leftover_str)
		buf = ft_strjoin(leftover_str, buf);
	tab = ft_strsplit(buf, '\n');
	(buf[ft_strlen(buf) - 1] == '\n') ? (leftover = 0) : (leftover = 1);
	i = 0;
	while (tab[i])
	{
		content = new_struct(fd, (leftover && !tab[i + 1] ? 1 : 0), tab[i]);
		if (!(*begin_list))
			(*begin_list) = ft_lstnew(content, sizeof(t_list));
		else
		{
			new_list = ft_lstnew(content, sizeof(t_list));
			ft_lstadd_back(&(*begin_list), new_list);
		}
		i++;
	}
}

void	del_leftover(int fd, t_list **begin_list)
{
	t_list	*tmp;

	while (*begin_list)
	{
		if ((((t_struct*)(*begin_list)->content)->fd == fd)
			&& ((((t_struct*)(*begin_list)->content)->leftover) == 1))
		{
			tmp = *begin_list;
			*begin_list = (*begin_list)->next;
			tmp->next = NULL;	
			return ;
		}
		*begin_list = (*begin_list)->next;
	}
}


int 	get_next_line(const int fd, char **line)
{
	static t_list	*begin_list;
	char			*leftover_str;

	if (!(begin_list))
	{
		create_lines(NULL, fd, &begin_list);
		save_del(fd, line, &begin_list);
		return (1);
	}
	else
	{
		while (begin_list)
		{
			if (((t_struct*)begin_list->content)->fd == fd) 
			{	
				if ((((t_struct*)begin_list->content)->leftover) == 0)
				{
					save_del(fd, line, &begin_list);
					return (1); 
				}
				else
				{
					leftover_str = ft_strdup(((t_struct*)begin_list->content)->str);
					del_leftover(fd, &begin_list);
					create_lines(leftover_str, fd, &begin_list);
					save_del(fd, line, &begin_list);
					return (1);
				}
			}
			begin_list = begin_list->next;		
		}
	}
	return (0);
}
