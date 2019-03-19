/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <jdelpuec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:48:45 by lubernar          #+#    #+#             */
/*   Updated: 2019/03/18 11:12:42 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press(int key, t_param *d)
{
	d->walk_s = 0.1;
	d->key2 = key;
	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		system("killall afplay > /dev/null 2>&1");
		exit(0);
	}
	key == 123 || key == 0 ? d->move[0] = 1 : 0;
	key == 124 || key == 2 ? d->move[1] = 1 : 0;
	key == 125 || key == 1 ? d->move[2] = 1 : 0;
	key == 126 || key == 13 ? d->move[3] = 1 : 0;
	if (key == 46)
		d->d_map == 0 ? d->d_map++ : d->d_map--;
	key == 12 ? d->move[4] = 1 : 0;
	key == 14 ? d->move[5] = 1 : 0;
	key == 257 ? d->move[6] = 1 : 0;
	if (key == 35)
	{
		d->choose_text++;
		choose_str(d);
	}
	return (0);
}

int		key_release(int key, t_param *d)
{
	key == 123 || key == 0 ? d->move[0] = 0 : 0;
	key == 124 || key == 2 ? d->move[1] = 0 : 0;
	key == 125 || key == 1 ? d->move[2] = 0 : 0;
	key == 126 || key == 13 ? d->move[3] = 0 : 0;
	key == 12 ? d->move[4] = 0 : 0;
	key == 14 ? d->move[5] = 0 : 0;
	key == 257 ? d->move[6] = 0 : 0;
	return (0);
}

int		player_move(t_param *d)
{
	d->old_time = clock();
	if (d->move[0] || d->move[1] || d->move[2] || d->move[3]
	|| d->move[4] || d->move[5] || d->move[6])
		move(d);
	bzero(d->addr, d->h * d->w * 4);
	ray(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	d->time = clock();
	d->d_time += (d->time - d->old_time);
	if (d->d_time > CLOCKS_PER_SEC)
	{
		d->fps = 1 / ((d->time - d->old_time) / CLOCKS_PER_SEC);
		d->d_time = 0;
	}
	d->tmp = ft_itoa((int)d->fps);
	init_map(d, 0, 0);
	d->d_map == 1 ?
	mlx_put_image_to_window(d->mlx, d->win, d->map, d->w - (d->xmax * 4), 0)
	: 0;
	mlx_string_put(d->mlx, d->win, 10, 10, 16777215, d->tmp);
	free(d->tmp);
	if (system("killall -s afplay > /dev/null 2>&1") == 256)
		choose_music(d);
	return (0);
}

int		ft_exit(t_param *d)
{
	mlx_destroy_window(d->mlx, d->win);
	system("killall afplay > /dev/null 2>&1");
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_param	d;

	ac != 2 ? error("Usage : ./wolf <mapname>\n") : ac;
	checkpath(av[1]);
	signal(2, quit);
	initialize_d(&d);
	fd = open(av[1], O_NOFOLLOW | O_RDONLY);
	fd == -1 ? error("Open error.\n") : fd;
	d.ymax = count_lines(fd, av);
	read_map(fd, d.ymax, &d);
	d.xmax = xmax(d.tab);
	valid_map(&d) == 0 ? error("Invalid map.\n") : 0;
	initialize_mlx(&d);
	mlx_hook(d.win, 2, 0, key_press, &d);
	mlx_hook(d.win, 3, 0, key_release, &d);
	mlx_loop_hook(d.mlx, player_move, &d);
	mlx_hook(d.win, 17, 1L, ft_exit, &d);
	mlx_loop(d.mlx);
	return (0);
}
