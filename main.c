/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/30 12:47:12 by bboucher         ###   ########.fr       */
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
		printf("return: %d result line: %s\n", get_next_line(fd, &line), line);
		i++;
	}
	return (c);
}
