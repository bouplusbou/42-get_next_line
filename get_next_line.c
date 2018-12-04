/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:35:20 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/04 09:25:29 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_one_line(char **str, char **line)
{
	char	*leftover;
	char	*one_line;
	char	*tmp;

	if (ft_strchr(*str, '\n'))
	{
		one_line = (*str);
		leftover = (ft_strchr(one_line, '\n') + 1);
		leftover[-1] = '\0';
		*line = ft_strdup(one_line);
		one_line = (*str);
		tmp = *str;
		*str = ft_strdup(leftover);
		free(tmp);
		return (1);
	}
	else if (ft_strequ(*str, ""))
	{
		ft_strclr(*line);
		return (0);
	}
	*line = ft_strdup(*str);
	ft_strclr(*str);
	return (1);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	len = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_strnew(len);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tab[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			rd;
	char		*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1
			|| (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL))
		return (-1);
	while (!ft_strchr(tab[fd], '\n')
			&& (rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = tab[fd];
		tab[fd] = ft_join(tmp, buf);
		ft_strclr(buf);
		free(tmp);
	}
	return (get_one_line(&tab[fd], line));
}
