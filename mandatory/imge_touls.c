/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imge_touls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:57:39 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/26 09:17:47 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	a_xpm_to_imge(t_gam *gam, int x, int y)
{
	gam->img.c1 = mlx_xpm_file_to_image(gam->mlx, "mandatory/shep1/C1.xpm",
			&x, &y);
	gam->img.w = mlx_xpm_file_to_image(gam->mlx, "image/wal.xpm", &x, &y);
	gam->img.n = mlx_xpm_file_to_image(gam->mlx, "image/n70.xpm", &x, &y);
	gam->img.e0 = mlx_xpm_file_to_image(gam->mlx, "exit/ext1.xpm", &x, &y);
	gam->img.ef = mlx_xpm_file_to_image(gam->mlx, "exit/ext2.xpm", &x, &y);
	gam->p.p_d = mlx_xpm_file_to_image(gam->mlx, "wlf/pn.xpm", &x, &y);
	gam->p.p1_r = mlx_xpm_file_to_image(gam->mlx, "wlf/pr1.xpm", &x, &y);
	gam->p.p2_r = mlx_xpm_file_to_image(gam->mlx, "wlf/pr2.xpm", &x, &y);
	gam->p.p3_r = mlx_xpm_file_to_image(gam->mlx, "wlf/pr3.xpm", &x, &y);
	gam->p.p1_l = mlx_xpm_file_to_image(gam->mlx, "wlf/pl1.xpm", &x, &y);
	gam->p.p2_l = mlx_xpm_file_to_image(gam->mlx, "wlf/pl2.xpm", &x, &y);
	gam->p.p3_l = mlx_xpm_file_to_image(gam->mlx, "wlf/pl3.xpm", &x, &y);
	gam->p.p_u = mlx_xpm_file_to_image(gam->mlx, "wlf/pu.xpm", &x, &y);
	if (!gam->img.c1 || !gam->img.w || !gam->img.n || !gam->img.e0
		|| !gam->img.ef || !gam->p.p_d || !gam->p.p1_r || !gam->p.p2_r
		|| !gam->p.p3_r || !gam->p.p1_l || !gam->p.p2_l || !gam->p.p3_l
		|| !gam->p.p_u)
		print_error(7);
}

int	you_lose(t_gam *gam)
{
	put_p(gam, gam->p.x, gam->p.y, 'D');
	return (0);
}

void	print_numbr(int x, int x1)
{
	if (x >= 10)
		print_numbr(x / 10, x1);
	write(1, &"0123456789"[x % 10], 1);
	if (x == x1)
		write(1, "\n", 1);
}

static	int	b_len_num(long n)
{
	int	x;

	x = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		x++;
	}
	while (n >= 1)
	{
		n /= 10;
		x++;
	}
	return (x);
}

void	ft_itoa(int n, char *p)
{
	int		i;
	int		a;
	long	nb;

	nb = n;
	a = b_len_num(nb);
	p[a--] = '\0';
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		p[0] = '-';
		i++;
	}
	while (a >= i)
	{
		p[a--] = nb % 10 + 48;
		nb /= 10;
	}
}
