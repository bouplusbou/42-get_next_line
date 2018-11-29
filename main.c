/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/29 16:00:18 by bboucher         ###   ########.fr       */
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
		get_next_line(fd, &line);
		printf("%s\n", line);
		i++;
	}
	return (c);
}
