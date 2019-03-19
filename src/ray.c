/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <lubernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:27:28 by jdelpuec          #+#    #+#             */
/*   Updated: 2019/03/19 11:47:50 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ray_set2(t_param *d)
{
	if (d->ray_dirx < 0)
	{
		d->stepx = -1;
		d->sidex = (d->xray - d->mapx) * d->deltax;
	}
	else
	{
		d->stepx = 1;
		d->sidex = (d->mapx + 1 - d->xray) * d->deltax;
	}
	if (d->ray_diry < 0)
	{
		d->stepy = -1;
		d->sidey = (d->yray - d->mapy) * d->deltay;
	}
	else
	{
		d->stepy = 1;
		d->sidey = (d->mapy + 1 - d->yray) * d->deltay;
	}
}

void	ray_set(t_param *d, int x)
{
	d->xray = d->xpos;
	d->yray = d->ypos;
	d->xcam = (2 * x) / (double)d->w - 1;
	d->ray_dirx = d->xdir + d->xplane * d->xcam;
	d->ray_diry = d->ydir + d->yplane * d->xcam;
	d->mapx = (int)d->xray;
	d->mapy = (int)d->yray;
	d->deltax = sqrt(1 + (d->ray_diry * d->ray_diry)
		/ (d->ray_dirx * d->ray_dirx));
	d->deltay = sqrt(1 + (d->ray_dirx * d->ray_dirx)
		/ (d->ray_diry * d->ray_diry));
	d->wall = 0;
	ray_set2(d);
}

void	ray2(t_param *d, int x)
{
	int y;

	y = 0;
	if (d->side == 0)
		d->dist_err = fabs(((double)d->mapx - d->xray
			+ (1 - d->stepx) / 2) / d->ray_dirx);
	else
		d->dist_err = fabs(((double)d->mapy - d->yray
			+ (1 - d->stepy) / 2) / d->ray_diry);
	d->line = fabs((double)d->h / d->dist_err);
	y = (d->line / -2 + d->h / 2);
	d->endline = (d->line / 2 + d->h / 2);
	y < 0 ? y = 0 : 0;
	d->endline >= d->h ? d->endline = d->h - 1 : 0;
	wall_textures(d, y, x);
	floor_textures(d, x, y);
}

void	ray(t_param *d)
{
	int x;

	x = 0;
	while (x < d->w)
	{
		ray_set(d, x);
		while (d->wall == 0)
		{
			d->sidex < d->sidey ? d->mapx += d->stepx : (d->mapy += d->stepy);
			d->sidex < d->sidey ? d->side = 0 : 0;
			d->sidex >= d->sidey ? d->side = 1 : 0;
			d->sidex < d->sidey ?
				d->sidex += d->deltax : (d->sidey += d->deltay);
			if (d->tab[d->mapx][d->mapy] != 0)
				d->wall = 1;
			else
				d->wall = 0;
		}
		ray2(d, x);
		x++;
	}
}
