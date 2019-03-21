/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <lubernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:38:14 by lubernar          #+#    #+#             */
/*   Updated: 2019/03/19 15:21:19 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		valid_map(t_param *d)
{
	int	i;
	int	j;

	i = 0;
	d->ypos > d->xmax ? error("Invalid map.\n") : 0;
	d->xpos > d->ymax ? error("Invalid map.\n") : 0;
	while (i < d->ymax)
	{
		j = 0;
		while (j < d->xmax)
		{
			if (i == 0 || i == d->ymax - 1)
				if (d->tab[i][j] != 1)
					return (0);
			if (j == 0 && d->tab[i][j] != 1)
				return (0);
			if (j == d->xmax - 1 && d->tab[i][j] != 1)
				return (0);
			if (d->tab[i][j] != 1 && d->tab[i][j] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
