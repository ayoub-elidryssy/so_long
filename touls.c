/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:55:48 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/26 08:32:47 by aelidrys         ###   ########.fr       */
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
	exit (0);
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
	if (x == 5)
		print_str("error\n");
	if (x == 6)
		print_str("invalid character in map\n");
	if (x == 7)
		print_str("error in convert xpm file to image\n");
}
