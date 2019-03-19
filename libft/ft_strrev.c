/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:44:22 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 12:44:33 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		x;
	int		y;
	char	tmp;

	x = 0;
	y = ft_strlen(str) - 1;
	if (str == NULL)
		return (NULL);
	if (y == -1)
		return (str);
	while (x < y)
	{
		tmp = str[x];
		str[x] = str[y];
		str[y] = tmp;
		x++;
		y--;
	}
	return (str);
}
