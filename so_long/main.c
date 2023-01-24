/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:42:55 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/23 10:17:53 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int a, char **av)
{
	char	*p;
	a_gam	gam;
	int b;
	
	b = 0;
	gam.m_y = 0;
	gam.n = 0;
	a = open(av[1], O_RDONLY);
	p = get_next_line(a);
	gam.map = spl(p, '\n');
	print_error(check_map(p));
	gam.mlx = mlx_init();
	gam.ptr = mlx_new_window(gam.mlx, a_lent(gam.map[0]) * 70, arg_lent(gam.map) * 70, "WOLF AND SHEEP");
	a_xpm_to_imge(&gam, 0, 0);
	while (gam.map[gam.m_y])
	{
		gam.m_x = 0;
		while (gam.map[gam.m_y][gam.m_x])
		{
			if (gam.map[gam.m_y][gam.m_x] != 'P')
				put_img(&gam, gam.m_x, gam.m_y, gam.map[gam.m_y][gam.m_x]);
			if (gam.map[gam.m_y][gam.m_x] == 'P')
				put_p(&gam, gam.m_x, gam.m_y, 'R');
			gam.m_x++;
		}
		gam.m_y++;
	}
	enmy_pos(&gam, 0, 0);
	mlx_loop_hook(gam.mlx, a_animation,&gam);
	mlx_hook(gam.ptr, 2, 0, sw_img,&gam);
	mlx_loop(gam.mlx);
}