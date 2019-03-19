/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:11:29 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 17:11:32 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t x;

	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen((char *)s));
	x = 0;
	while (s[x])
	{
		if (s[x] == (unsigned char)c)
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}
