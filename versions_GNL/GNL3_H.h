/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:18:14 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/28 09:47:25 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

int				get_next_line(const int fd, char **line);

typedef struct	s_fd
{
	int			fd;
	char		*str;
	struct s_fd	*next;
}				t_fd;

#endif
