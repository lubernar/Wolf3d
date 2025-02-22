/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:34:33 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/08 19:33:46 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		((char *)dst)[x] = ((char *)src)[x];
		x++;
	}
	return (dst);
}
