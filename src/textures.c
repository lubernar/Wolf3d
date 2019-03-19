/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <lubernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:09:16 by lubernar          #+#    #+#             */
/*   Updated: 2019/03/18 10:46:03 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_textures(t_param *d, int y, int x)
{
	d->tex_y = (y * 2 - d->h + d->line) * (d->tex_h / 2) / d->line;
	if (d->side == 0 && d->ray_dirx > 0)
		d->addr[y * d->w + x] = d->walls_addr[0][d->tex_y * d->size[0]
		+ d->tex_x];
	else if (d->side == 0 && d->ray_dirx < 0)
		d->addr[y * d->w + x] = d->walls_addr[1][d->tex_y * d->size[2]
		+ d->tex_x];
	else if (d->side == 1 && d->ray_diry > 0)
		d->addr[y * d->w + x] = d->walls_addr[2][d->tex_y * d->size[4]
		+ d->tex_x];
	else
		d->addr[y * d->w + x] = d->walls_addr[3][d->tex_y * d->size[6]
		+ d->tex_x];
}

void	wall_textures(t_param *d, int y, int x)
{
	if (d->side == 1)
		d->wall_x = d->xray + ((d->mapy - d->yray + (1 - d->stepy)
		/ 2) / d->ray_diry) * d->ray_dirx;
	else
		d->wall_x = d->yray + ((d->mapx - d->xray + (1 - d->stepx)
		/ 2) / d->ray_dirx) * d->ray_diry;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * d->tex_w);
	if (d->side == 0 && d->ray_dirx > 0)
		d->tex_x = d->tex_w - d->tex_x - 1;
	if (d->side == 1 && d->ray_diry < 0)
		d->tex_x = d->tex_w - d->tex_x - 1;
	while (y < d->endline)
	{
		draw_textures(d, y, x);
		y++;
	}
}

void	side(t_param *d)
{
	d->p_dist = 0.0;
	d->wall_dist = d->dist_err;
	if (d->side == 0 && d->ray_dirx > 0)
	{
		d->floor_x = d->mapx;
		d->floor_y = d->mapy + d->wall_x;
	}
	else if (d->side == 0 && d->ray_dirx < 0)
	{
		d->floor_x = d->mapx + 1.0;
		d->floor_y = d->mapy + d->wall_x;
	}
	else if (d->side == 1 && d->ray_diry > 0)
	{
		d->floor_x = d->mapx + d->wall_x;
		d->floor_y = d->mapy;
	}
	else
	{
		d->floor_x = d->mapx + d->wall_x;
		d->floor_y = d->mapy + 1.0;
	}
}

void	floor_textures(t_param *d, int x, int y)
{
	side(d);
	d->wall_dist = d->dist_err;
	d->p_dist = 0.0;
	if (d->endline < 0)
		d->endline = d->h;
	y = d->endline + 1;
	while (y < d->h)
	{
		d->c_dist = d->h / (2.0 * y - d->h);
		d->wei = (d->c_dist - d->p_dist) / (d->wall_dist - d->p_dist);
		d->c_floor_x = d->wei * d->floor_x + (1.0 - d->wei) * d->xpos;
		d->c_floor_y = d->wei * d->floor_y + (1.0 - d->wei) * d->ypos;
		d->floor_texx = (int)(d->c_floor_x * d->tex_w) % d->tex_w;
		d->floor_texy = (int)(d->c_floor_y * d->tex_h) % d->tex_h;
		d->addr[y * d->w + x] = d->floor_addr[d->floor_texy
			* d->lon2 + d->floor_texx];
		d->addr[(d->h - y - 1) * d->w + x] = d->ceiling_addr[d->floor_texy
			* d->lon3 + d->floor_texx];
		y++;
	}
}
