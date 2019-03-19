/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:45:46 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/09 15:59:44 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	x;
	char	*temp;

	x = 0;
	if (NULL ==
		(temp = (char *)malloc(sizeof(*temp) * (ft_strlen((char *)s1) + 1))))
		return (NULL);
	while (s1[x])
	{
		temp[x] = s1[x];
		x++;
	}
	temp[x] = '\0';
	return (temp);
}
