/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/23 13:23:44 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int c, char **v)
{
	int		fd;
	int		i = 0;
	char	*line;

	fd = open(v[1], O_RDONLY);
//	(void)v;
//	fd = 1;
//	printf("fd: %i\n", fd);
	while (i < ft_atoi(v[2]))
	{
		get_next_line(fd, &line);
		ft_putendl(line);
//		printf("--------------------------\n");
		i++;
	}
	return (c);
}

/*
 * creer une liste par fd
 * un maillon = une ligne
 * pour ca, on stock dans str jusqu'a ce que la nwl est trouvee
 * realloc str a chaque passage + si newline, garder en memoire ce qu'il y a dans le buffer apres le newline
 *
 */
