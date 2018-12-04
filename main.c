/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/04 09:14:36 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int c, char **v)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(v[1], O_RDONLY);
	i = 0;
	line = ft_strnew(0);
	while (i < ft_atoi(v[2]))
	{
		//		get_next_line(fd, &line);
		printf("%d line: %s\n", get_next_line(fd, &line), line);
		i++;
	}
	ft_strdel(&line);
	return (c);
}
/*
int main(int ac, char **av)
{
	char *line;
	int fd;

	(void)ac;
	(void)av;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);
	return (0);
}
*/
