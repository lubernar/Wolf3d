/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:03:08 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 17:03:46 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t x;

	x = 0;
	if (n == 0)
		return ;
	while (x < n)
	{
		((char *)s)[x] = 0;
		x++;
	}
}
