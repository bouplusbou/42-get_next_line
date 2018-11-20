/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:30:56 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/19 10:41:18 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_isblank(s[start]))
		start++;
	end = ft_strlen(s);
	while (end && ft_isblank(s[end - 1]))
		end--;
	if ((end - start) < 0)
		return (ft_strsub(s, start, 0));
	return (ft_strsub(s, start, (end - start)));
}
