/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:58:11 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 11:30:57 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t x;

	if (s1 == NULL || s2 == NULL)
		return (0);
	x = 0;
	while (x < n && s1[x] == s2[x])
	{
		if (s1[x] == '\0' && s2[x] == '\0')
			return (1);
		x++;
	}
	if (x == n)
		return (1);
	return (0);
}
