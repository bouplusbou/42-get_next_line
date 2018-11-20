/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:17:35 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/20 16:09:11 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	int	rd;
	int	i;

	i = 0;
	rd = 1;
	while (rd != 0)
	{
		(*line) = ft_strnew(BUFF_SIZE);
		rd = read(fd, (*line), BUFF_SIZE);
//		printf("rd: %i\n", rd);
		ft_putendl(*line);
		ft_memdel((void**)&(*line));
		i++;
	}
	return (0);
}
