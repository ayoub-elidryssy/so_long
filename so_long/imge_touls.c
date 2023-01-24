/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imge_touls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:57:39 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/23 06:51:23 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	a_xpm_to_imge(a_gam *gam, int x, int y)
{
	gam->img.c1 = mlx_xpm_file_to_image(gam->mlx, "shep/C3.xpm", &x, &y);
	gam->img.c2 = mlx_xpm_file_to_image(gam->mlx, "shep/C4.xpm", &x, &y);
	//gam->img.c3 = mlx_xpm_file_to_image(gam->mlx, "shep/C4.xpm", &x, &y);
	gam->img.w = mlx_xpm_file_to_image(gam->mlx, "wal.xpm", &x, &y);	
	gam->img.n = mlx_xpm_file_to_image(gam->mlx, "n70.xpm", &x, &y);	
	gam->img.a1 = mlx_xpm_file_to_image(gam->mlx, "enimi/A1.xpm", &x, &y);	
	gam->img.a2 = mlx_xpm_file_to_image(gam->mlx, "enimi/A2.xpm", &x, &y);	
	gam->img.a3 = mlx_xpm_file_to_image(gam->mlx, "enimi/A3.xpm", &x, &y);	
	gam->img.a4 = mlx_xpm_file_to_image(gam->mlx, "enimi/A4.xpm", &x, &y);	
	gam->img.a5 = mlx_xpm_file_to_image(gam->mlx, "enimi/A5.xpm", &x, &y);	
	gam->img.e0 = mlx_xpm_file_to_image(gam->mlx, "exit/ext1.xpm", &x, &y);
	gam->img.ef = mlx_xpm_file_to_image(gam->mlx, "exit/ext2.xpm", &x, &y);
	gam->p.p_n = mlx_xpm_file_to_image(gam->mlx, "wlf/pn.xpm", &x, &y);
	gam->p.p1_r = mlx_xpm_file_to_image(gam->mlx, "wlf/pr1.xpm", &x, &y);
	gam->p.p2_r = mlx_xpm_file_to_image(gam->mlx, "wlf/pr2.xpm", &x, &y);
	gam->p.p3_r = mlx_xpm_file_to_image(gam->mlx, "wlf/pr3.xpm", &x, &y);
	gam->p.p1_l = mlx_xpm_file_to_image(gam->mlx, "wlf/pl1.xpm", &x, &y);
	gam->p.p2_l = mlx_xpm_file_to_image(gam->mlx, "wlf/pl2.xpm", &x, &y);
	gam->p.p3_l = mlx_xpm_file_to_image(gam->mlx, "wlf/pl3.xpm", &x, &y);
	gam->p.p_d = mlx_xpm_file_to_image(gam->mlx, "wlf/pd.xpm", &x, &y);
	gam->p.p_u = mlx_xpm_file_to_image(gam->mlx, "wlf/pu.xpm", &x, &y);
}