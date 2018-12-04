/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/12/04 10:49:15 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			main(int c, char **v)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 1;
	while (i < c)
	{
		if ((fd = open(v[i], O_RDONLY)) == -1)
			printf("ERROR\n");
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%d - |%s|\n", ret, line);
			free(line);
		}
		i++;
	}
	while (1)
		c = 1;
	return (0);
}

