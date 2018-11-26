/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:08:26 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/26 16:10:07 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strctrim(char const *s, char c)
{
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == c)
		start++;
	end = ft_strlen(s);
	while (end && s[end - 1] == c)
		end--;
	if ((end - start) < 0)
		return (ft_strsub(s, start, 0));
	return (ft_strsub(s, start, (end - start)));
}
