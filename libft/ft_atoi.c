/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:54:31 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/19 10:38:35 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	neg;
	int	res;

	while (ft_isspace(*s))
		s++;
	neg = (*s == '-');
	if (*s == '-' || *s == '+')
		s++;
	res = 0;
	while (ft_isdigit(*s))
	{
		res *= 10;
		res += (*s - '0');
		s++;
	}
	return (neg ? -res : res);
}
