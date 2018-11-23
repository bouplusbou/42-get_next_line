/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:18:14 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/23 11:29:19 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFF_SIZE 4
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "includes/libft.h"
///////////////////////////////////////////////////////////////suppr
#include <stdio.h>

int get_next_line(const int fd, char **line);

typedef struct	s_struct
{
	int		fd;
	int		leftover;
	char	*str;
}				t_struct;

#endif
