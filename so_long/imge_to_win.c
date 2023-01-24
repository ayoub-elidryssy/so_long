/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imge_to_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:45:55 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/23 06:55:37 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_p(a_gam *gam, int x, int y, int k)
{
	if (k == 'N')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p_n, x * 70, y * 70);
	if (k == 'R' && gam->b[1] != 1 && gam->b[1] != 2)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p1_r, x * 70, y * 70);
	if (k == 'R' && gam->b[1] == 1)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p2_r, x * 70, y * 70);
	if (k == 'R' && gam->b[1] == 2)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p3_r, x * 70, y * 70);
	if (k == 'L' && gam->b[0] != 1 && gam->b[0] != 2)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p1_l, x * 70, y * 70);
	if (k == 'L' && gam->b[0] == 1)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p2_l, x * 70, y * 70);
	if (k == 'L' && gam->b[0] == 2)
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p3_l, x * 70, y * 70);
	if (k == 'D')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p_n, x * 70, y * 70);//L
	if (k == 'U')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->p.p_u, x * 70, y * 70);
	return (1);
}

int	put_img(a_gam *gam, int x, int y, int k)
{
	if (k == 'A')
	{
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.n, x * 70, y * 70);
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.a1, x * 70, y * 70);
	}
	if (k == 'C')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.c1, x * 70, y * 70);
	if (k == 'c')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.c2, x * 70, y * 70);
	if (k == '1')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.w, x * 70, y * 70);
	if (k == '0')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.n, x * 70, y * 70);	
	if (k == 'E')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.e0, x * 70, y * 70);
	if (k == 'e')
		mlx_put_image_to_window(gam->mlx, gam->ptr, gam->img.ef, x * 70, y * 70);
	return (1);
}

void	sw1_img(a_gam *gam, int k, int c)
{
		gam->map[gam->p.y][gam->p.x] = '0';
		if (k == 'L')
			put_img(gam, gam->p.x--, gam->p.y, '0');
		if (k == 'R')
			put_img(gam, gam->p.x++, gam->p.y, '0');
		if (k == 'D')
			put_img(gam, gam->p.x, gam->p.y++, '0');
		if (k == 'U')
			put_img(gam, gam->p.x, gam->p.y--, '0');
		gam->map[gam->p.y][gam->p.x] = c;
		put_p(gam, gam->p.x, gam->p.y, k);
}

void	check_exit(a_gam *gam, int x, int y, int s)
{
	if (gam->map[y][x] == 'e' || gam->map[y][x] == 'A')
		exit (0);
	if (s == 0 || s == 1)
	{
		if (gam->b[s] == 3)
			gam->b[s] = 0;
		gam->b[s]++;
	}
	if (s == 0)
		sw1_img(gam, 'L', 'P');
	if (s == 1)
		sw1_img(gam, 'R', 'P');
	if (s == 2)
		sw1_img(gam, 'U', 'P');
	if (s == 3)
		sw1_img(gam, 'D', 'P');
}

int	sw_img(int k, a_gam *gam)
{
	if (k == 53)
		exit (0);
	a_sersh(gam->map, 'P', &gam->p.y, &gam->p.x);
	if (k == 123 && gam->map[gam->p.y][gam->p.x - 1] != 'E' && gam->map[gam->p.y][gam->p.x - 1] != '1')
		check_exit(gam, gam->p.x - 1, gam->p.y, 0);
	if (k == 124 && gam->map[gam->p.y][gam->p.x + 1] != 'E' && gam->map[gam->p.y][gam->p.x + 1] != '1')
		check_exit(gam, gam->p.x + 1, gam->p.y, 1);
	if (k == 126 && gam->map[gam->p.y - 1][gam->p.x] != 'E' && gam->map[gam->p.y - 1][gam->p.x] != '1')
		check_exit(gam, gam->p.x, gam->p.y - 1, 2);
	if (k == 125 && gam->map[gam->p.y + 1][gam->p.x] != 'E' && gam->map[gam->p.y + 1][gam->p.x] != '1')
		check_exit(gam, gam->p.x, gam->p.y + 1, 3);
	if (a_sersh_n(gam->map, 'C') == 0)
	{
		if (a_sersh(gam->map, 'E', &gam->m_y, &gam->m_x))
		{
			gam->map[gam->m_y][gam->m_x] = 'e';
			put_img(gam, gam->m_x, gam->m_y, 'e');
		}
	}
	return (0);
}