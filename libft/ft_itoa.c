/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:53:57 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/13 15:36:08 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_fill(char *s, int n, int x)
{
	int neg;

	neg = 1;
	if (n < 0)
	{
		s[0] = '-';
		neg = -1;
	}
	while (n < -9 || n > 9)
	{
		s[x--] = ((n % 10) * neg) + 48;
		n = n / 10;
	}
	s[x] = ((n % 10) * neg) + 48;
}

char			*ft_itoa(int n)
{
	int		x;
	int		nb;
	char	*str;

	x = 0;
	nb = n;
	if (n < 0)
		x++;
	while (nb < -9 || nb > 9)
	{
		nb = nb / 10;
		x++;
	}
	if (NULL == (str = (char *)malloc(sizeof(*str) * (x + 2))))
		return (NULL);
	str[x + 1] = '\0';
	ft_fill(str, n, x);
	return (str);
}
