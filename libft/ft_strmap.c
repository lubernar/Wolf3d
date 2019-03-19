/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:31:26 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 11:40:12 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	x;
	char	*str;

	if (s == NULL || f == NULL)
		return (NULL);
	x = 0;
	str = (char *)malloc(sizeof(*str) * ((ft_strlen((char *)s) + 1)));
	if (str == NULL)
		return (NULL);
	while (s[x])
	{
		str[x] = f(s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}
