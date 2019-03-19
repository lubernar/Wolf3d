/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <lubernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:32:41 by lubernar          #+#    #+#             */
/*   Updated: 2019/03/19 11:44:19 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		count_words(char **str, t_param *d)
{
	int			i;
	static int	j;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(*str[i]) && *str[i] != 'X')
			error("Invalid file.\n");
		if (*str[i] == 'X')
		{
			if (d->xpos != 0)
				error("Too many player spawns.\n");
			d->xpos = j + 0.5;
			d->ypos = i + 0.5;
		}
		i++;
	}
	j++;
	if (j == d->ymax && d->xpos == 0)
		error("Spawn not initialized.\n");
	return (i);
}

int		count_lines(int fd, char **av)
{
	int		ymax;
	char	*line;

	fd = open(av[1], O_RDONLY);
	ymax = 0;
	while (get_next_line(fd, &line))
	{
		ymax++;
		free(line);
	}
	close(fd);
	return (ymax);
}

int		xmax(int **tab)
{
	int	j;
	int	xmax;

	xmax = 0;
	j = 0;
	if (tab[0] == NULL)
		return (0);
	while (tab[0][j] != 2147483647)
	{
		j++;
		xmax++;
	}
	return (xmax);
}

int		str_to_tab(t_param *d, char **str, char *line, int xtab)
{
	int	istrue;

	istrue = 1;
	while (str[xtab])
	{
		d->tab[d->ytab][xtab] = ft_atoi(str[xtab]);
		xtab++;
		free(str[xtab - 1]);
	}
	free(str);
	free(line);
	d->tab[d->ytab++][xtab] = 2147483647;
	return (istrue);
}

void	read_map(const int fd, int ymax, t_param *d)
{
	char	*line;
	char	**str;
	int		j;
	int		istrue;

	j = 0;
	d->ytab = 0;
	istrue = 0;
	if ((d->tab = (int**)malloc(sizeof(int*) * (ymax + 1))) == NULL)
		return ;
	while (get_next_line(fd, &line))
	{
		d->xtab = 0;
		while (!ft_isdigit(line[j]) && line[j])
			j++;
		line[j] == '\0' ? error("Invalid file.\n") : 0;
		if (ft_isdigit(line[j]) || line[j] == '-')
			str = ft_strsplit(line, ' ');
		if (!(d->tab[d->ytab] = malloc(sizeof(int) * (count_words(str, d)
		+ 1))))
			return ;
		istrue = str_to_tab(d, str, line, d->xtab);
	}
	!istrue ? error("Invalid file.\n") : d->tab[0];
}
