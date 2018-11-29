/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:08:56 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/26 10:31:58 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	read_list(t_list *li)
{
	while (li)
	{
		printf("lst_str: %s\n", (((t_struct*)li->content)->str));
		printf("lst_fd: %d\n", (((t_struct*)li->content)->fd));
		li = li->next;
		return ;
	}
	printf("li doesn't exist.\n");
}






t_struct	*new_struct(int fd, char *str)
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

char		*find_nl(char *str)
{
	while (*str == '\n')
		str++;
	while (*str)
	{
		if (*str == '\n')
		{
			return (str + 1);
		}
		str++;
	}
	return (NULL);
}

static void	del_struct(void	*content, size_t size)
{
	(void)size;
	ft_strdel(&((t_struct*)content)->str);
	ft_memdel(&content);
}

int			find_line(t_list **li, char **line, int fd)
{
	char	*tmp;
	char	*str;

	while (*li)
	{
		if (((t_struct*)(*li)->content)->fd == fd)
		{
			str = ((t_struct*)(*li)->content)->str;
			tmp = find_nl(str);
			if (!tmp)
			{
				*line = ft_strdup(str);
				ft_lstdelone(&(*li), &del_struct);
				return (0);
			}
			tmp[-1] = '\0';
			*line = ft_strdup(str);
			((t_struct*)(*li)->content)->str = ft_strdup(tmp);
//			ft_strdel(&str);
			return (1);
		}
		*li = (*li)->next;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int				rd;
	char			*buf;
	char			*str;
	static t_list	*li;

	if (fd < 0 || !line || !(buf = ft_strnew(BUFF_SIZE)) || !(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!find_line(&li, line, fd))
	{
		rd = 1;
		while (!find_nl(str) && rd != 0)
		{
			rd = read(fd, buf, BUFF_SIZE);
			str = ft_strjoin(str, buf);
			if (rd == -1)
				return (-1);
		}
		!li ? li = ft_lstnew(new_struct(fd, str), sizeof(t_struct)) 
			: ft_lstadd_back(&li, ft_lstnew(new_struct(fd, str), sizeof(t_struct)));
		find_line(&li, line, fd);
	} 
	return (1);
}
