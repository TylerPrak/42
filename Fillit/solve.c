/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 22:18:48 by tprak             #+#    #+#             */
/*   Updated: 2017/09/18 01:37:57 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_coords(t_tet_piece *tet, t_var *vl, int y, int x)
{
	int i;
	int xsum;
	int ysum;

	i = 0;
	while (i < 4)
	{
		xsum = x + tet->zpos[i].x;
		ysum = y + tet->zpos[i].y;
		if (ft_check_letter(vl, ysum, xsum) != 1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_place(t_tet_piece *tetris, t_var *vl, int y, int x)
{
	int j;
	int xsum;
	int ysum;

	j = 0;
	while (j < 4)
	{
		ysum = y + tetris->zpos[j].y;
		xsum = x + tetris->zpos[j].x;
		vl->map[ysum][xsum] = tetris->letter;
		j++;
	}
	return (0);
}

int		ft_remove(t_tet_piece *tetris, t_var *vl, int y, int x)
{
	int flag;

	flag = 0;
	while (y < vl->size)
	{
		x = 0;
		while (x < vl->size)
		{
			if (vl->map[y][x] == tetris->letter)
			{
				if (++flag == 1)
					ft_store_tranpos(tetris, vl, y, x);
				vl->map[y][x] = '.';
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_valid_place(t_tet_piece *tet, t_var *vl, int y, int x)
{
	if (vl->map[y][x] == '.' && ft_check_coords(tet, vl, y, x) == 1
			&& tet->tranpos.y <= y)
	{
		if (tet->tranpos.x < x || (tet->tranpos.x < vl->size &&
					tet->tranpos.y < y))
		{
			return (1);
		}
	}
	return (0);
}

int		ft_solve(t_tet_piece *tetris, t_var *vl, int i, int x)
{
	int y;

	y = 0;
	while (y < vl->size)
	{
		x = 0;
		while (x < vl->size)
		{
			if (ft_valid_place(&tetris[i], vl, y, x) != 0)
			{
				if (ft_place(&tetris[i], vl, y, x) == 0)
					i++;
				if (i == vl->tpieces)
					return (1);
				if (ft_solve(tetris, vl, i, 0))
					return (1);
				i--;
				ft_remove(&tetris[i], vl, 0, 0);
			}
			x++;
		}
		y++;
	}
	ft_clear_tranpos(&tetris[i]);
	return (0);
}
