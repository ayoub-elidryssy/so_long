/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_touls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:07:39 by aelidrys          #+#    #+#             */
/*   Updated: 2023/01/23 07:08:30 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enmy(a_gam *gam, int y, int x )
{
	a_enmy	*an;
	a_enmy	*a1;

	an = (a_enmy *)malloc(sizeof(a_enmy));
	an->x = x;
	an->y = y;
	an->next = NULL;
	if (gam && gam->a)
	{
		a1 = gam->a;
		while(a1->next)
			a1 = a1->next;
		a1->next = an;
	}
	else
		gam->a = an;
}

void	enmy_pos(a_gam *gam, int y, int x)
{
	while (gam->map[y])
	{
		x = 0;
		while (gam->map[y][x])
		{
			if (gam->map[y][x] == 'A')
				add_enmy(gam , y, x);
			x++;
		}
		y++;
	}
}
