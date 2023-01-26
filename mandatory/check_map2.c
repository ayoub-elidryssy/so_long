/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:34:10 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/26 08:16:07 by aelidrys         ###   ########.fr       */
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

int	valid_path(t_gam *gam, int n)
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

int	check_characters(t_gam *gam, int x, int y)
{
	y = -1;
	while (gam->map[++y])
	{
		x = -1;
		while (gam->map[y][++x])
		{
			if (gam->map[y][x] != '0' && gam->map[y][x] != '1'
				&& gam->map[y][x] != 'C' && gam->map[y][x] != 'E'
				&& gam->map[y][x] != 'P')
				return (0);
		}
	}
	return (1);
}
