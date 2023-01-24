/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flod_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:34:10 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/23 10:50:12 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flod_fill(char **map, int x, int y, int n)
{
	if (!map)
		return ;
	if (map[x][y] != 'P')
		map[x][y] = '2';
	if (map[x][y + 1] == 'C' || map[x][y + 1] == '0')
		flod_fill(map, x, y + 1, n);
	if (map[x + 1][y] == 'C' || map[x + 1][y] == '0')
		flod_fill(map, x + 1, y, n);
	if (x > 0 && (map[x - 1][y] == 'C' || map[x - 1][y] == '0'))
		flod_fill(map, x - 1, y, n);
	if (y > 0 && (map[x][y - 1] == 'C' || map[x][y - 1] == '0'))
		flod_fill(map, x, y - 1, n);
}

int	valid_path(a_gam *gam, int n)
{
	int	x;
	int	y;

	if (!a_sersh(gam->map, 'P', &x, &y))
		print_error(-1);
	flod_fill(gam->map, x, y, n);
	y = a_sersh_n(gam->map, 'C');
	x = 0;
	while (gam->map[x])
		free(gam->map[x++]);
	free(gam->map);
	if (y != 0)
		return (-5);
	return (1);
}

int	a_random1(a_gam *gam, int *a)
{
	int b;
	a = &b;
	b = (unsigned long)a % 10;
	if (b == gam->a->d)
		return (a_random1(gam, NULL));
	return (b);
	
}
