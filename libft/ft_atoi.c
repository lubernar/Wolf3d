/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:46:02 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/13 14:11:01 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t			x;
	int				n;
	long			nb;

	x = 0;
	nb = 0;
	n = 1;
	while (str[x] == '\f' || str[x] == '\t' || str[x] == '\n' ||
	str[x] == '\r' || str[x] == '\v' || str[x] == ' ')
		x++;
	if (str[x] == '-')
		n = -1;
	if (str[x] == '-' || str[x] == '+')
		x++;
	while ((str[x] > 47 && str[x] < 58) && str[x])
	{
		nb = (nb * 10) + ((str[x]) - 48);
		x++;
		if (nb < 0)
			return (n == 1) ? -1 : 0;
	}
	return (nb * n);
}
