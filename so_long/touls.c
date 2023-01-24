/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:55:48 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/22 17:48:08 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	arg_lent(char **p)
{
	size_t	n;

	n = 0;
	while (p[n])
		n++;
	return (n);
}

int	a_sersh(char **map, char c, int *x, int *y)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b++] == c)
			{
				*x = a;
				*y = b - 1;
				return (1);
			}
		}
		a++;
	}
	return (0);
}

int	a_sersh_n(char **map, char c)
{
	int	a;
	int	b;
	int	x;

	a = 0;
	x = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b++] == c)
				x++;
		}
		a++;
	}
	return (x);
}

void	print_str(char *s)
{
		while (s && *s)
			write (1, s++, 1);
}

void	print_error(int x)
{
	if (x == -5)
		print_str("invalid path\n");
	if (x == -4)
		print_str("extra exit\n");
	if (x == -3)
		print_str("collectible not found\n");
	if (x == -2)
		print_str("invalid number of player\n");
	if (x == -1)
		print_str("Player does not exist\n");
	if (x == 0)
		print_str("extra new line\n");
	if (x == 2)
		print_str("invalid map\n");
	if (x == 3)
		print_str("invalid wall\n");
	if (x == 4)
		print_str("exit not found\n");
	if (x != 1)
		exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:58:12 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/22 17:47:42 by aelidrys         ###   ########.fr       */
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
	void	*C1;
	void	*C2;
	void	*C3;
	void	*E;
	void	*A1;
	void	*A2;
	void	*A3;
	void	*A4;
	void	*A5;
	void	*e;
	void	*W;
	void	*N;
}	a_imge;

typedef struct
{
	int		x;
	int		y;
	void	*P_N;
	void	*P1_R;
	void	*P2_R;
	void	*P3_R;
	void	*P1_L;
	void	*P2_L;
	void	*P3_L;
	void	*P_U;
	void	*P_D;
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
	int		a[4];
	void	*mlx;
	void	*ptr;
	char	**map;
	a_plyr	P;
	a_imge	img;
	a_enmy	*A;
}	a_gam;


int		a_sersh(char **map, char c, int *x, int *y);
void	flod_fill(char **map, int x, int y, int n);
int		put_img(a_gam *win, int x, int y, int k);
int		put_p(a_gam *win, int x, int y, int k);
void	add_enmy(a_gam *gam, int y, int x);
void	enmy_pos(a_gam *gam, int y, int x);
int		a_sersh_n(char **map, char c);
int		valid_path(a_gam *gm, int n);
char	**spl(char const *s, char c);
int		sw_img(int k, a_gam *mlx);
void	a_xpm_to_imge(a_gam *win, int x, int y);
int		a_animation(a_gam *win);
size_t	arg_lent(char **p);
int		check_map(char *p);
void	print_error(int x);

#endif