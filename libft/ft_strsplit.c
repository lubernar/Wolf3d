/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:38:53 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 11:36:35 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count(char const *s, char c)
{
	size_t	x;
	size_t	count;

	x = 0;
	count = 0;
	if (s[x] != c && s[x] != '\0')
		count++;
	while (s[x])
	{
		if (s[x] == c && (s[x + 1] != c && s[x + 1] != '\0'))
			count++;
		x++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	x;
	size_t	y;
	size_t	w;
	char	**tab;

	if (s == NULL)
		return (NULL);
	x = 0;
	y = 0;
	w = 0;
	if (NULL == (tab = (char **)malloc(sizeof(*tab) * (ft_count(s, c) + 1))))
		return (NULL);
	while (s[x] && w < (ft_count(s, c) + 1))
	{
		while (s[x] == c && s[x])
			x++;
		y = x;
		while (s[y] != c && s[y])
			y++;
		if (s[y] != '\0' || w < ft_count(s, c))
			tab[w++] = ft_strsub(s, x, (y - x));
		x = y;
	}
	tab[w] = 0;
	return (tab);
}
