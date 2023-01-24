/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:58:12 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/23 19:00:38 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct
{
	int		y;
	int		x;
	void	*c1;
	void	*c2;
	void	*c3;
	void	*e0;
	void	*a1;
	void	*a2;
	void	*a3;
	void	*a4;
	void	*a5;
	void	*ef;
	void	*w;
	void	*n;
}	a_imge;

typedef struct
{
	int		x;
	int		y;
	void	*p_n;
	void	*p1_r;
	void	*p2_r;
	void	*p3_r;
	void	*p1_l;
	void	*p2_l;
	void	*p3_l;
	void	*p_u;
	void	*p_d;
}	a_plyr;

typedef struct b_enmy
{
	int				x;
	int				y;
	int				d;
	struct b_enmy	*next;
}	a_enmy;

typedef struct 
{
	int		m_x;
	int		m_y;
	int		n_c;
	int		n;
	int		b[4];
	void	*mlx;
	void	*ptr;
	char	**map;
	a_plyr	p;
	a_imge	img;
	a_enmy	*a;
}	a_gam;


int		a_sersh(char **map, char c, int *x, int *y);
void	flod_fill(char **map, int x, int y, int n);
int		put_img(a_gam *gam, int x, int y, int k);
int		put_p(a_gam *gam, int x, int y, int k);
void	anim_of_enemy(a_gam *gam, int x, int y, int n);
void	enmy_movs(a_gam *gam, int x, int y, int c);
void	anim_of_sheep(a_gam *gam, int x, int y);
void	a_xpm_to_imge(a_gam *gam, int x, int y);
void	add_enmy(a_gam *gam, int y, int x);
void	enmy_pos(a_gam *gam, int y, int x);
int		a_sersh_n(char **map, char c);
int		valid_path(a_gam *gam, int n);
char	**spl(char const *s, char c);
int		sw_img(int k, a_gam *gam);
int		a_animation(a_gam *gam);
int		a_random1(a_gam *gam, int *b);
size_t	arg_lent(char **p);
int		check_map(char *p);
void	print_error(int x);
int		a_random(void);

#endif