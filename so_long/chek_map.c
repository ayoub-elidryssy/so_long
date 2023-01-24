/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:14:18 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/22 08:04:36 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	comp_tab(int *tab, char **map, int n)
{
	int	x;
	int	y;

	x = -1;
	tab = malloc(n * sizeof(int));
	while (map[++x])
		tab[x] = a_lent(map[x]);
	x = 0;
	while (tab && x + 1 < n)
	{
		y = x + 1;
		while(y < n)
		{
			if (tab[x] != tab[y++])
			{
				free(tab);
				return (0);
			}
		}
		x++;	
	}
	free(tab);
	return (1);
}

int	comp_str(char *s)
{
	int	x;

	x = 0;
	while (s[x + 1])
			if (s[x++] != '1')
				return (0);
	return (1);
}

int	valid_map(a_gam *gam, int n)
{
	int	x;
	int	y;

	y = a_lent(gam->map[0]) - 1;
	x = 0;
	if (!comp_str(gam->map[0]) || !comp_str(gam->map[n - 1]))
		return (3);
	while(gam->map[x])
	{
		if (gam->map[x][0] != '1' || gam->map[x][y] != '1')
			return (3);
		x++;
	}
	if (a_sersh_n(gam->map, 'C') == 0)
		return (-3);
	if (!a_sersh_n(gam->map, 'E'))
		return (4);
	if (a_sersh_n(gam->map, 'E') > 1)
		return (-4);
	return (valid_path(gam, arg_lent(gam->map)));
}

int	check_new_line(char *p)
{
	while (p && *p)
	{
		if (*p == '\n' && *(p + 1) == '\n')
			return (0);
		p++;
	}
	if (p && *p == '\0' && *(p - 1) == '\n')
		return (0);
	return (1);
}


int	check_map(char *p)
{
	int		n;
	a_gam	gam;

	n = -1;
	gam.map = spl(p, '\n');
	if (!gam.map)
		return (5);
	if (!check_new_line(p))
		return (0);
	if (a_sersh_n(gam.map, 'P') == 0)
		return (-1);
	if (a_sersh_n(gam.map, 'P') > 1)
		return (-2);
	if (comp_tab(NULL, gam.map, arg_lent(gam.map)) != 1)
		return (2);
	return (valid_map(&gam, arg_lent(gam.map)));
}
