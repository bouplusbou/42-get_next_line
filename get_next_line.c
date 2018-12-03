/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:35:20 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/03 18:11:48 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	get_one_line(char *str, char **line)
{
	char	*leftover;
	char	*one_line;
	char	*tmp;

//	printf("inside ONELINE\n");
	if (ft_strchr(str, '\n'))
	{
		printf("inside first if ONELINE\n");
		printf("str: %s\n", str);
		one_line = str;
		leftover = (ft_strchr(one_line, '\n') + 1);
		leftover[-1] = '\0';
		*line = ft_strdup(one_line);
		tmp = str;
		str = ft_strdup(leftover);
		free(tmp);
		return (1);
	}
	else if (ft_strequ(str, ""))
	{
//		printf("inside else if ONELINE\n");
		ft_strclr(*line);
		return (0);
	}
//	printf("after if / else if ONELINE\n");
	*line = ft_strdup(str);
	ft_strclr(str);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tab[OPEN_MAX] = {NULL};
	char		buf[BUFF_SIZE + 1];
	int			rd;
	char		*tmp;

	if (fd < 0 || !line || (rd = read(fd, buf, 0)) < 0)
		return (-1);
	while (!ft_strchr(tab[fd], '\n')
			&& (rd = read(fd, buf, BUFF_SIZE) > 0))
	{
		tmp = ft_strdup(tab[fd]);
		tab[fd] = ft_strjoin(tmp, buf);
		printf("tab[%d]: %s\n", fd, tab[fd]);
		ft_strclr(buf);
		free(tmp);
	}
	if (rd < 0)
		return (-1);
	return (get_one_line(tab[fd], line));
}
