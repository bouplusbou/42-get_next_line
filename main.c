/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:06:25 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/20 17:15:48 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int c, char **v)
{
	int		fd;
	char	*str;

	fd = open(v[1], O_RDONLY);
//	(void)v;
//	fd = 1;
	printf("fd: %i\n", fd);
	get_next_line(fd, &str);
	return (c);
}

/*
 * stocker dans str tout ce qui se trouve dans un fd
 * realloc str a chaque passage
 * creer une liste par fd
 * un maillon = une ligne
 *
 *
 */
