/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:20:47 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/10 15:45:05 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t x;

	x = ft_strlen((char *)s);
	if ((ft_strlen((char *)s) == 0) && (unsigned char)c != '\0')
		return (NULL);
	if ((unsigned char)c == '\0')
		return ((char *)s + x);
	while (x != 0)
	{
		x--;
		if (s[x] == (unsigned char)c)
			return ((char *)s + x);
	}
	return (NULL);
}
