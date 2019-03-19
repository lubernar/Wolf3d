/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:48:56 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/10 14:56:19 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t x;
	size_t y;
	size_t s;

	x = 0;
	y = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[x] && x < len)
	{
		if (haystack[x] == needle[y])
		{
			s = x;
			while (haystack[s] == needle[y] && s < len)
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
