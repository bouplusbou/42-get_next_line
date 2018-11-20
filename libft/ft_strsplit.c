/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:27:15 by bboucher          #+#    #+#             */
/*   Updated: 2018/11/19 13:40:03 by bboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc_word(const char *s, char c)
{
	char	*str;
	int		size;
	int		i;

	size = 0;
	while ((s[size] != c) && (s[size] != '\0'))
		size++;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	i = 0;
	while ((s[size] != c) && (s[size] != '\0'))
	{
		str[i] = s[size];
		size++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if ((s[i - 1] == '\0' && s[i] != c) || (s[i - 1] == c && s[i] != c))
			w++;
		i++;
	}
	return (w);
}

static void	ft_clean(char **tab, int j)
{
	int	i;

	i = 0;
	while (i <= j)
		ft_strdel(&tab[i++]);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s
		|| !(tab = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i - 1] == '\0' && s[i] != c) || (s[i - 1] == c && s[i] != c))
		{
			if (!(tab[j] = ft_malloc_word((s + i), c)))
			{
				ft_clean(tab, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
