/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <jdelpuec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:50:15 by lubernar          #+#    #+#             */
/*   Updated: 2019/03/25 15:52:42 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	initialize_d(t_param *d)
{
	int	i;

	i = 0;
	while (i < 7)
		d->move[i++] = 0;
	d->xpos = 0;
	d->ypos = 0;
	d->xdir = -1.0;
	d->ydir = 0.0;
	d->xplane = 0.0;
	d->yplane = 0.6;
	d->w = 600;
	d->h = 600;
	d->tex_w = 480;
	d->tex_h = 480;
	d->time = 0;
	d->old_time = 0;
	d->d_time = 0;
	d->d_map = 0;
	d->choose_m = 0;
	d->choose_text = 0;
	if (!(d->textures = (char**)malloc(sizeof(char*) * 6)))
		error("Malloc error.\n");
}

void	initialize_textures(t_param *d)
{
	initialize_xpm(d);
	d->walls_addr[0] = (int *)mlx_get_data_addr(d->walls_text[0], &(d->bpp),
		&d->s_l, &d->end);
	d->walls_addr[1] = (int *)mlx_get_data_addr(d->walls_text[1], &(d->bpp),
		&d->s_l, &d->end);
	d->walls_addr[2] = (int *)mlx_get_data_addr(d->walls_text[2], &(d->bpp),
		&d->s_l, &d->end);
	d->walls_addr[3] = (int *)mlx_get_data_addr(d->walls_text[3], &(d->bpp),
		&(d->s_l), &(d->end));
	d->floor_addr = (int *)mlx_get_data_addr(d->floor_te, &(d->bpp), &(d->s_l),
		&(d->end));
	d->ceiling_addr = (int *)mlx_get_data_addr(d->ceiling_te, &(d->bpp),
		&(d->s_l), &(d->end));
}

void	choose_str2(t_param *d)
{
	if (d->choose_text == 2)
	{
		system("killall afplay > /dev/null 2>&1");
		d->choose_m = 2;
		d->textures[0] = "textures/lava.xpm";
		d->textures[1] = "textures/lava.xpm";
		d->textures[2] = "textures/lava.xpm";
		d->textures[3] = "textures/lava.xpm";
		d->textures[4] = "textures/floorislava.xpm";
		d->textures[5] = "textures/skystars.xpm";
	}
	if (d->choose_text == 3)
	{
		system("killall afplay > /dev/null 2>&1");
		d->choose_m = 3;
		d->textures[0] = "textures/snow.xpm";
		d->textures[1] = "textures/snow.xpm";
		d->textures[2] = "textures/snow.xpm";
		d->textures[3] = "textures/snow.xpm";
		d->textures[4] = "textures/ice.xpm";
		d->textures[5] = "textures/skystars.xpm";
	}
	//choose_music(d);
	initialize_textures(d);
}

void	choose_str(t_param *d)
{
	d->choose_text = d->choose_text % 4;
	if (d->choose_text == 0)
	{
		system("killall afplay > /dev/null 2>&1");
		d->choose_m = 0;
		d->textures[0] = "textures/arbres2.xpm";
		d->textures[1] = "textures/raptor.xpm";
		d->textures[2] = "textures/puppy.xpm";
		d->textures[3] = "textures/arbres.xpm";
		d->textures[4] = "textures/feuilles.xpm";
		d->textures[5] = "textures/ciel.xpm";
	}
	// choose_music(d);
	if (d->choose_text == 1)
	{
		system("killall afplay > /dev/null 2>&1");
		d->choose_m = 1;
		d->textures[0] = "textures/maze.xpm";
		d->textures[1] = "textures/maze.xpm";
		d->textures[2] = "textures/maze.xpm";
		d->textures[3] = "textures/maze.xpm";
		d->textures[4] = "textures/gazon.xpm";
		d->textures[5] = "textures/skystars.xpm";
	}
	choose_str2(d);
}

void	initialize_mlx(t_param *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->w, d->h, "Wolf3D");
	d->img = mlx_new_image(d->mlx, d->w, d->h);
	d->addr = (int *)mlx_get_data_addr(d->img, &(d->bpp), &(d->s_l),
		&(d->end));
	d->map = mlx_new_image(d->mlx, 4 * d->xmax, 4 * d->ymax);
	d->map_addr = (int *)mlx_get_data_addr(d->map, &(d->bpp), &(d->s_l),
		&(d->end));
	if (!(d->map_text = mlx_xpm_file_to_image(d->mlx, "textures/arbres.xpm",
	&d->lon, &d->lar)))
		ft_free(d, 5);
	d->map_addr2 = (int *)mlx_get_data_addr(d->map_text, &(d->bpp), &(d->s_l),
		&(d->end));
	choose_str(d);
	ray(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
