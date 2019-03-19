/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:43:21 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 11:34:01 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *str)
{
	size_t	x;

	if (str == NULL)
		return ;
	x = 0;
	while (str[x])
	{
		ft_putchar(str[x]);
		x++;
	}
	ft_putchar('\n');
}
