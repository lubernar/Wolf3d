/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:03:42 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/13 11:32:24 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	if (NULL == (zone = (void *)malloc(sizeof(*zone) * size)))
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
