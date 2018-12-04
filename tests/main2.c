/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/30 13:14:24 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int c, char **v)
{
	int		fd;
	int		fd2;
	int		fd3;
//	int		fd4;
//	int		fd5;
	int		i;
	char	*line;
	
	fd = open(v[1], O_RDONLY);
	fd2 = open(v[2], O_RDONLY);
	fd3 = open(v[3], O_RDONLY);
//	fd4 = open(v[4], O_RDONLY);
//	fd5 = open(v[5], O_RDONLY);
	i = 0;
	line = ft_strnew(0);
	while (i < ft_atoi(v[4]))
	{
		printf("fd: %d return: %d line: %s\n", fd, get_next_line(fd, &line), line);
		printf("fd: %d return: %d line: %s\n", fd2, get_next_line(fd2, &line), line);
		printf("fd: %d return: %d line: %s\n", fd3, get_next_line(fd3, &line), line);
//		printf("fd: %d return: %d line: %s\n", fd4, get_next_line(fd4, &line), line);
//		printf("fd: %d return: %d line: %s\n", fd5, get_next_line(fd5, &line), line);
		i++;
	}
	return (c);
}
