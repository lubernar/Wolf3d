/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <jdelpuec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:58:37 by jdelpuec          #+#    #+#             */
/*   Updated: 2019/03/25 14:37:20 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_free2(t_param *d, int nb, int i)
{
	if (nb == 4)
	{
		free(d->textures);
		d->xpos != 0 ? error("Too many player spawns.\n") : 0;
		d->xpos == 0 ? error("Spawn not initialized.\n") : 0;
	}
	if (nb == 5)
	{
		free(d->textures);
		i = 0;
		while (i < d->ymax)
			free(d->tab[i++]);
		free(d->tab);
		error("Invalid map.\n");
	}
}

void	ft_free(t_param *d, int nb)
{
	int	i;

	i = 0;
	ft_putnbr(nb);
	if (nb == 1)
	{
		free(d->textures);
		error("Open error.\n");
	}
	if (nb == 2)
	{
		free(d->textures);
		error("Invalid file.\n");
	}
	if (nb == 3)
	{
		free(d->textures);
		error("Malloc error.\n");
	}
	ft_free2(d, nb, i);
}

void	quit(int err)
{
	if (err == 2)
	{
		system("killall afplay > /dev/null 2>&1");
		exit(0);
	}
}

void	checkpath(char *s)
{
	char	*check;
	char	*check2;
	int		x;

	x = ft_strlen(s);
	if (x < 4)
		error("Invalid file name.\n");
	check = ".w3d";
	check2 = ft_strsub(s, x - 4, 4);
	if (ft_strcmp(check, check2) != 0)
		error("Invalid file name.\n");
	free(check2);
}

void	initialize_xpm(t_param *d)
{
	if (!(d->walls_text[0] = mlx_xpm_file_to_image(d->mlx, d->textures[0],
		&d->size[0], &d->size[1])))
		error("Texture missing.\n");
	if (!(d->walls_text[1] = mlx_xpm_file_to_image(d->mlx, d->textures[1],
		&d->size[2], &d->size[3])))
		error("Texture missing.\n");
	if (!(d->walls_text[2] = mlx_xpm_file_to_image(d->mlx, d->textures[2],
		&d->size[4], &d->size[5])))
		error("Texture missing.\n");
	if (!(d->walls_text[3] = mlx_xpm_file_to_image(d->mlx, d->textures[3],
		&d->size[6], &d->size[7])))
		error("Texture missing.\n");
	if (!(d->floor_te = mlx_xpm_file_to_image(d->mlx, d->textures[4],
		&d->lon2, &d->lar2)))
		error("Texture missing.\n");
	if (!(d->ceiling_te = mlx_xpm_file_to_image(d->mlx, d->textures[5],
		&d->lon3, &d->lar3)))
		error("Texture missing.\n");
}
