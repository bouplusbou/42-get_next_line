/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:17:35 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/21 18:07:26 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	int		rd;
	int		i;
	char	*buf;
	char	**tab;
	t_list	*li;
	t_list	*new;

	(void)line;
	rd = 1;
	buf = ft_strnew(BUFF_SIZE);
	rd = read(fd, buf, BUFF_SIZE);

	tab = ft_strsplit(buf, '\n');
	i = 0;
	li = ft_lstnew("", 0);
	///// il faudrait que content soit une struct pour pouvoir rentrer a la fois tab[i] et un flag "leftover"
	while (tab[i])
	{
		new = ft_lstnew(tab[i], (ft_strlen(tab[i])));
		ft_lstadd(&li, new);
		i++;
	}
	while (li)
	{
		ft_putendl(li->content);
		li = li->next;
	}
	return (0);
}
