/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:50:52 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/23 19:10:44 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_of_sheep(a_gam *gam, int x, int y)
{
	while (gam->map[y])
	{
		x = 0;
		while (gam->map[y][x])
		{
			if (gam->n == 12001)
				gam->n = 0;
			if (gam->map[y][x] == 'C')
			{
				if (gam->n == 0)
					put_img(gam, x, y, 'C');
				if (gam->n == 8000)
					put_img(gam, x, y, 'c');
			}
			x++;
		}
		y++;
	}
	gam->n++;
}

void	enmy_movs(a_gam *gam, int x, int y, int c)
{
	if (gam->map[y][x + 1] == '0' || gam->map[y + 1][x] == '0'
		|| gam->map[y][x - 1] == '0' || gam->map[y - 1][x] == '0')
	{
		gam->map[y][x] = '0';
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.n, x * 70, y * 70);
	}
	if ((gam->map[y][x + 1] == '0' || gam->map[y][x + 1] == 'P') && c != 'L')
	{
		gam->map[y][gam->a->x++ + 1] = 'A';
		gam->a->d = 'R';
	}
	else if ((gam->map[y + 1][x] == '0' || gam->map[y + 1][x] == 'P') && c != 'U')
	{
		gam->map[gam->a->y++ + 1][x] = 'A';
		gam->a->d = 'D';
	}
	else if ((gam->map[y][x - 1] == '0' || gam->map[y][x - 1] == 'P') && c != 'R')
	{
		gam->map[y][gam->a->x-- - 1] = 'A';
		gam->a->d = 'L';
	}
	else if ((gam->map[y - 1][x] == '0' || gam->map[y - 1][x] == 'P') && c != 'D')
	{
		gam->map[gam->a->y-- - 1][x] = 'A';
		gam->a->d = 'U';
	}
	else
	{
		if ((gam->map[y][x - 1] == '0' || gam->map[y][x - 1] == 'P') && c == 'R')
			gam->map[y][gam->a->x-- - 1] = 'A';
		if ((gam->map[y][x + 1] == '0' || gam->map[y][x + 1] == 'P') && c == 'L')
			gam->map[y][gam->a->x++ + 1] = 'A';
		if ((gam->map[y - 1][x] == '0' || gam->map[y - 1][x] == 'P') && c == 'D')
			gam->map[gam->a->y-- - 1][x] = 'A';
		if ((gam->map[y + 1][x] == '0' || gam->map[y + 1][x] == 'P') && c == 'U')
			gam->map[gam->a->y++ + 1][x] = 'A';
	}
}

void	anim_of_enemy(a_gam *gam, int x, int y, int n)
{
	if (n == 0 || n == 4000 || n == 8000 || n == 12000 || n == 16000)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.n, x, y);
	if (n == 0)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.a1, x, y);
	if (n == 4000)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.a2, x, y);
	if (n == 8000)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.a3, x, y);
	if (n == 12000)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.a4, x, y);
	if (n == 16000)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.a5, x, y);
}

int	a_animation(a_gam *gam)
{
	a_enmy	*tmp;

	tmp = gam->a;
	anim_of_sheep(gam, 0, 0);
	if (gam->n_c++ == 20002)
		gam->n_c = 0;
	while (gam->a)
	{	
		anim_of_enemy(gam, gam->a->x * 70, gam->a->y * 70, gam->n_c);
		if (gam->n_c == 20000)
			enmy_movs(gam, gam->a->x, gam->a->y, gam->a->d);
		gam->a = gam->a->next;
	}
	gam->a = tmp;
	return (0);
}
