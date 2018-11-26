/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/26 15:46:57 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int c, char **v)
{
	int		fd;
	int		i = 0;
	char	*line;
	
	fd = open(v[1], O_RDONLY);
	while (i < ft_atoi(v[2]))
	{
//		ft_putnbr(get_next_line(fd, &line));
		get_next_line(fd, &line);
		printf("line: %s\n", line);
//		printf("one\n");
		i++;
	}
	return (c);
}
