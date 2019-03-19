/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <jdelpuec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 10:24:31 by jdelpuec          #+#    #+#             */
/*   Updated: 2019/03/18 12:44:12 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	map2(t_param *d, int y, int x)
{
	d->mapy = 0;
	while (d->mapy < 4)
	{
		d->mapx = 0;
		while (d->mapx < 4)
		{
			if (d->tab[y][x] == 1)
				d->map_addr[((y * (int)4) + d->mapy)
				* (d->xmax * 4) + ((x * (int)4)
				+ d->mapx)] = d->map_addr2[(4 + d->mapy)
				* d->lon + (4 + d->mapx)];
			else
				d->map_addr[((y * (int)4) + d->mapy)
					* (d->xmax * 4) + ((x * (int)4) + d->mapx)] = 6579300;
			d->map_addr[(int)((d->xpos - 0.5) * 4 + d->mapy)
			* (d->xmax * 4) + (int)((d->ypos - 0.5) * 4 + d->mapx)] = 16777215;
			d->mapx++;
		}
		d->mapy++;
	}
}

void	init_map(t_param *d, int y, int x)
{
	y = 0;
	while (y < d->ymax)
	{
		x = 0;
		while (x < d->xmax)
		{
			map2(d, y, x);
			x++;
		}
		y++;
	}
}
