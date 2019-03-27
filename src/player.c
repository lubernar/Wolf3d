/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <jdelpuec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:05:22 by lubernar          #+#    #+#             */
/*   Updated: 2019/03/25 18:48:43 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		turn(t_param *d)
{
	if (d->move[0])
	{
		d->rota = -0.06;
		d->old_xdir = d->xdir;
		d->xdir = d->xdir * cos(-d->rota) - d->ydir * sin(-d->rota);
		d->ydir = d->old_xdir * sin(-d->rota) + d->ydir * cos(-d->rota);
		d->old_xplane = d->xplane;
		d->xplane = d->xplane * cos(-d->rota) - d->yplane * sin(-d->rota);
		d->yplane = d->old_xplane * sin(-d->rota) + d->yplane * cos(-d->rota);
	}
	if (d->move[1])
	{
		d->rota = 0.06;
		d->old_xdir = d->xdir;
		d->xdir = d->xdir * cos(-d->rota) - d->ydir * sin(-d->rota);
		d->ydir = d->old_xdir * sin(-d->rota) + d->ydir * cos(-d->rota);
		d->old_xplane = d->xplane;
		d->xplane = d->xplane * cos(-d->rota) - d->yplane * sin(-d->rota);
		d->yplane = d->old_xplane * sin(-d->rota) + d->yplane * cos(-d->rota);
	}
	return (0);
}

int		move(t_param *d)
{
	d->walk_s = 0.1;
	if (d->move[6])
		d->walk_s += 0.1;
	if (d->move[3])
	{
		d->rota = -0.06;
		if (d->tab[(int)(d->xpos + d->xdir * d->walk_s)][(int)d->ypos] == 0)
			d->xpos += d->xdir * d->walk_s;
		if (d->tab[(int)(d->xpos)][(int)(d->ypos + d->ydir * d->walk_s)] == 0)
			d->ypos += d->ydir * d->walk_s;
	}
	if (d->move[2])
	{
		d->rota = 0.06;
		if (d->tab[(int)(d->xpos - d->xdir * d->walk_s)][(int)d->ypos] == 0)
			d->xpos -= d->xdir * d->walk_s;
		if (d->tab[(int)(d->xpos)][(int)(d->ypos - d->ydir * d->walk_s)] == 0)
			d->ypos -= d->ydir * d->walk_s;
	}
	turn(d);
	side_steps(d);
	return (0);
}

int		side_steps(t_param *d)
{
	if (d->move[5])
	{
		if (d->tab[(int)(d->xpos + d->xplane * d->walk_s)][(int)d->ypos] == 0)
			d->xpos += d->xplane * d->walk_s;
		if (d->tab[(int)d->xpos][(int)(d->ypos + d->yplane * d->walk_s)] == 0)
			d->ypos += d->yplane * d->walk_s;
	}
	if (d->move[4])
	{
		if (d->tab[(int)(d->xpos - d->xplane * d->walk_s)][(int)d->ypos] == 0)
			d->xpos -= d->xplane * d->walk_s;
		if (d->tab[(int)d->xpos][(int)(d->ypos - d->yplane * d->walk_s)] == 0)
			d->ypos -= d->yplane * d->walk_s;
	}
	return (0);
}
