/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/26 16:30:18 by bboucher         ###   ########.fr       */
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
		if (get_next_line(fd, &line))
			printf("%s\n", line);
		i++;
	}
	return (c);
}
