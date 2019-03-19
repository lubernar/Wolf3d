/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelpuec <jdelpuec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:52:41 by lubernar          #+#    #+#             */
/*   Updated: 2019/03/18 11:04:38 by jdelpuec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	choose_music(t_param *d)
{
	d->choose_m == 0 ? system("afplay ./music/song-of-storms.mp3 &") : 0;
	d->choose_m == 1 ? system("afplay ./music/harry.mp3 &") : 0;
	d->choose_m == 2 ? system("afplay ./music/lavasong.mp3 &") : 0;
	d->choose_m == 3 ? system("afplay ./music/prisme.mp3 &") : 0;
}
