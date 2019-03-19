/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:30:51 by jdelpuec          #+#    #+#             */
/*   Updated: 2018/11/16 14:41:01 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fillstr(char *str, int nb, int x, int base)
{
	char			*defbase;
	unsigned int	nb2;

	defbase = "0123456789ABCDEF";
	nb2 = (nb < 0) ? -nb : nb;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0 && base == 10)
		str[0] = '-';
	while (nb2 != 0)
	{
		str[x--] = defbase[nb2 % base];
		nb2 = nb2 / base;
	}
	return (str);
}

char			*ft_itoa_base(int nb, int base)
{
	char			*str;
	int				x;
	unsigned int	nb2;

	x = 0;
	nb2 = (nb < 0) ? -nb : nb;
	if (nb < 0 && base == 10)
		x++;
	while (nb2 != 0)
	{
		nb2 = nb2 / base;
		x++;
	}
	if (NULL == (str = (char *)malloc(sizeof(*str) * x + 1)))
		return (NULL);
	str[x--] = '\0';
	return (ft_fillstr(str, nb, x, base));
}
