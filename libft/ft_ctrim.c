/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:00:27 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 16:08:01 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, int c)
{
	size_t	x;
	size_t	count;

	x = 0;
	count = 0;
	while (s[x] == c)
	{
		count++;
		x++;
	}
	if (s[x] == '\0')
		return (count);
	x = ft_strlen((char *)s) - 1;
	while (s[x] == c)
	{
		count++;
		x--;
	}
	return (count);
}

char			*ft_ctrim(char const *s, int c)
{
	size_t	x;
	size_t	y;
	char	*str;

	if (s == NULL)
		return (NULL);
	x = 0;
	y = 0;
	if (NULL == (str = (char *)malloc(sizeof(*str)
	* (ft_strlen((char *)s) - ft_count(s, c)) + 1)))
		return (NULL);
	if (((ft_strlen((char *)s) - ft_count(s, c)) + 1) == 1)
	{
		str[0] = '\0';
		return (str);
	}
	while (s[x] == c)
		x++;
	while (y < (ft_strlen((char *)s) - ft_count(s, c)))
	{
		str[y] = s[x + y];
		y++;
	}
	str[y] = '\0';
	return (str);
}
