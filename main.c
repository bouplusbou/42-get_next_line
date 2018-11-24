/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/24 16:31:04 by bboucher         ###   ########.fr       */
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
		get_next_line(fd, &line);
		ft_putendl(line);
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
