/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <lubernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:55:34 by jdelpuec          #+#    #+#             */
/*   Updated: 2019/03/19 15:38:30 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <time.h>
# include <signal.h>
# include <stdio.h>

typedef	struct		s_param
{
	void			*mlx;
	void			*win;
	void			*img;
	int				w;
	int				h;
	int				bpp;
	int				s_l;
	int				end;
	int				*addr;
	int				*walls_text[4];
	int				*walls_addr[4];
	int				*text_addr;
	int				*floor_addr;
	int				**tab;
	int				xtab;
	int				ytab;
	int				ymax;
	int				xmax;
	char			**textures;
	int				move[7];
	int				key2;
	double			xpos;
	double			ypos;
	double			xdir;
	double			ydir;
	double			xplane;
	double			yplane;
	double			old_xdir;
	double			old_xplane;
	double			rota;
	double			walk_s;
	double			xray;
	double			yray;
	double			ray_dirx;
	double			ray_diry;
	double			xcam;
	int				mapx;
	int				mapy;
	double			sidex;
	double			sidey;
	double			deltax;
	double			deltay;
	int				stepx;
	int				stepy;
	int				wall;
	int				side;
	double			dist_err;
	int				line;
	int				endline;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	int				tex_w;
	int				tex_h;
	int				color;
	int				size[7];
	double			wei;
	int				hei;
	double			floor_x;
	double			floor_y;
	double			weigt;
	double			c_floor_x;
	double			c_floor_y;
	int				floor_texx;
	int				floor_texy;
	double			wall_dist;
	double			p_dist;
	double			c_dist;
	int				w3;
	int				h3;
	void			*ceiling_te;
	int				*ceiling_addr;
	double			time;
	double			old_time;
	double			d_time;
	int				choose_m;
	double			fps;
	char			*tmp;
	void			*map;
	int				*map_addr;
	int				*map_addr2;
	int				d_map;
	int				*map_text;
	int				lon;
	int				lar;
	int				lon2;
	int				lar2;
	int				lon3;
	int				lar3;
	int				*floor_te;
	int				choose_text;
}					t_param;

int					count_lines(int fd, char **av);
void				read_map(const int fd, int ymax, t_param *d);
int					xmax(int **tab);
int					valid_map(t_param *d);
void				ray(t_param *d);
int					move(t_param *d);
void				initialize_d(t_param *d);
void				initialize_mlx(t_param *d);
void				wall_textures(t_param *d, int y, int x);
void				init_map(t_param *d, int y, int x);
void				floor_textures(t_param *d, int x, int y);
int					side_steps(t_param *d);
void				quit(int err);
void				choose_str(t_param *d);
void				choose_music(t_param *d);
void				checkpath(char *s);
void				initialize_xpm(t_param *d);
#endif
