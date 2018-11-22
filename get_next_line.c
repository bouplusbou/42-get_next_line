/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:17:35 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/22 16:51:48 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	read_list(t_list *begin_list)
{
	while (begin_list)
	{
//		ft_putchar(((t_struct*)begin_list->content)->str[0]);
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

void	del_content(t_struct *content, size_t size)
{
	//quoi faire avec size ?
	(void)size;
	ft_strdel(&(content->str));
	free(content);
}

void	show_line(int fd, char **line, t_list **begin_list)
{
	t_list	*tmp;
	t_list	*before;
	void	(*del)(void *, size_t);

	del = (&del_content);
	tmp = *begin_list;
	while (tmp)
	{
		if ((tmp->next)->content->fd == fd)
		{
			before = tmp;
			tmp = tmp->next;
			line = ft_strdup(tmp->content->str);
			before->next = tmp->next;
			ft_lstdelone(&tmp, del((t_struct*)(tmp->content), sizeof(t_struct)));
			return ;
		}
		tmp = tmp->next;
	}
}


int 	get_next_line(const int fd, char **line)
{
	int			rd;
	int			i;
	int			leftover;
	char		*buf;
	char		*buf_tmp;
	char		**tab;
	t_list		*begin_list;
	t_list		*new_list;
	t_struct	*content;

	(void)line;
	buf = ft_strnew(BUFF_SIZE);
	rd = read(fd, buf, BUFF_SIZE);
	
	// pas de bn
	buf_tmp = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(buf, '\n'))
	{
		rd = read(fd, buf_tmp, BUFF_SIZE);	
		buf = ft_strjoin(buf, buf_tmp);
	}
	
	// split le buf 
	tab = ft_strsplit(buf, '\n');

	// dernier char de buf == bn
	(buf[ft_strlen(buf) - 1] == '\n') ? (leftover = 0) : (leftover = 1);
	
	// cree un maillon par line + le leftover
	content = new_struct(-2, -2, "initialisation");
	begin_list = ft_lstnew(content, sizeof(t_list));
	i = 0;
	while (tab[i])
	{
		// ajouter leftover au dernier element
		content = new_struct(fd, (leftover && !tab[i + 1] ? 1 : 0), tab[i]);
		new_list = ft_lstnew(content, sizeof(t_list));
		ft_lstadd_back(&begin_list, new_list);
		i++;
	}


	// stocker dans line + delone
	show_line(fd, line, &begin_list);



	// lire le contenu de la liste 
//	read_list(begin_list);	
	

	
	/*
	// free le contenu et la structure
	if (vector != NULL)
	{
		free (vector->data);
		free (vector);
	}
	*/	
	return (0);
}
