/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:41:23 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/22 13:50:35 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *new;

	new = NULL;
	if (!ptr)
	{
		if (!(ptr = ft_memalloc(size)))
			return (NULL);
	}
	if (size <= 0)
		ft_memdel(ptr);
	else
	{
		if (!(new = ft_memalloc(size)))
			return (NULL);
		ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
	}
	return (new);
}
