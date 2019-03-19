/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:57:00 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/10 15:00:24 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t x;

	x = 0;
	while (s1[x] == s2[x] && s1[x])
		x++;
	return (((unsigned char)s1[x]) - ((unsigned char)s2[x]));
}
