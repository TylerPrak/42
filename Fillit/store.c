/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 18:32:26 by tprak             #+#    #+#             */
/*   Updated: 2017/09/18 01:36:44 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clear_tranpos(t_tet_piece *tetris)
{
	tetris->tranpos.y = 0;
	tetris->tranpos.x = -1;
}

void	ft_store_tranpos(t_tet_piece *tet, t_var *vl, int y, int x)
{
	tet->tranpos.y = y;
	tet->tranpos.x = x;
	vl->map[y][x] = '.';
}

void	ft_store_zpos(t_tet_piece *tetris, int h)
{
	while (h < 4)
	{
		tetris->zpos[h].y = (h == 0) ? 0 :
			tetris->tpos[h].y - tetris->tpos[0].y;
		tetris->zpos[h].x = (h == 0) ? 0 :
			tetris->tpos[h].x - tetris->tpos[0].x;
		h++;
	}
}

void	ft_store_tetpos(t_tet_piece *tet, int y, int x, int *h)
{
	tet->tpos[*h].y = y;
	tet->tpos[*h].x = x;
	if ((*h += 1) == 5)
		*h = 0;
}

int		ft_store(t_tet_piece *tetris, t_var *vl, int x, int i)
{
	int hashes;
	int	y;

	ZERO_CHECK((vl->buf = (char**)malloc(sizeof(char) * 500)), ft_error());
	while (i < vl->tpieces)
	{
		vl->buf = ft_strsplit(tetris[i].buf, '\n');
		y = 0;
		hashes = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (vl->buf[y][x] != '.')
					ft_store_tetpos(&tetris[i], y, x, &hashes);
				x++;
			}
			x++;
			y++;
		}
		ft_store_zpos(&tetris[i], 0);
		i++;
	}
	return (0);
}
