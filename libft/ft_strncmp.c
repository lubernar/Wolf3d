/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:01:29 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/10 15:12:53 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	x = 0;
	while (s1[x] == s2[x] && x < n && s1[x])
		x++;
	if (x == n)
		return (0);
	return (((unsigned char)s1[x]) - ((unsigned char)s2[x]));
}
