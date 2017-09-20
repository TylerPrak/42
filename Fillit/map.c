/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:30:51 by tprak             #+#    #+#             */
/*   Updated: 2017/09/15 05:47:19 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_min_map_size(t_var *vl)
{
	int hashes;

	hashes = vl->tpieces * 4;
	while (hashes > SQUARED(vl->size))
		vl->size++;
	return (vl->size);
}

void	ft_print_map(t_var *vl, int y, int x)
{
	while (y < vl->size)
	{
		x = 0;
		while (x < vl->size)
		{
			write(1, &vl->map[y][x], 1);
			x++;
			if (x == vl->size)
				write(1, "\n", 1);
		}
		y++;
	}
}

char	**ft_map(t_var *vl, int y, int x)
{
	vl->map = (char**)malloc(sizeof(char*) * vl->size + 1);
	vl->map[vl->size] = NULL;
	while (y < vl->size)
	{
		vl->map[y] = (char*)malloc(sizeof(char) * vl->size);
		x = 0;
		while (x < vl->size)
		{
			vl->map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (vl->map);
}
