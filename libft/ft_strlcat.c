/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:24:45 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/13 10:49:18 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l;

	l = ft_strlen(dst);
	if (l < size)
	{
		ft_strncat(dst, (char *)src, (size - l - 1));
		return (l + ft_strlen((char *)src));
	}
	else
		return ((ft_strlen((char *)src) + size));
}
