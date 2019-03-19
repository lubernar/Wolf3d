/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:35:38 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/10 17:50:46 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		if (((unsigned char *)s1)[x] == ((unsigned char *)s2)[x])
			x++;
		else
			return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
	}
	if (x == n)
		return (0);
	return (0);
}
