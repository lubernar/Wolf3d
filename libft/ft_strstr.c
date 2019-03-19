/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:55:00 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/10 14:47:49 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t x;
	size_t y;
	size_t s;

	x = 0;
	y = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[x])
	{
		if (haystack[x] == needle[y])
		{
			s = x;
			while (haystack[s] == needle[y])
			{
				s++;
				y++;
				if (needle[y] == '\0')
					return ((char *)haystack + x);
			}
			y = 0;
		}
		x++;
	}
	return (NULL);
}
