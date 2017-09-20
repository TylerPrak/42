/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 20:16:23 by tprak             #+#    #+#             */
/*   Updated: 2017/09/18 01:48:30 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(void)
{
	ft_putendl("error");
	return (0);
}

int		main(int ac, char **ag)
{
	t_tet_piece	tetris[26];
	t_var		vl;

	vl.size = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit [target_file]\n");
		return (0);
	}
	NEG_CHECK((vl.fd = open(ag[1], O_RDONLY)), ft_error());
	NEG_CHECK((vl.tpieces = ft_read(tetris, &vl, 0)), ft_error());
	vl.size = ft_get_min_map_size(&vl);
	ft_store(tetris, &vl, 0, 0);
	ft_map(&vl, 0, 0);
	while (ft_solve(tetris, &vl, 0, 0) != 1)
	{
		vl.size++;
		vl.map = ft_map(&vl, 0, 0);
	}
	NEG_CHECK(close(vl.fd), ft_error());
	ft_print_map(&vl, 0, 0);
	return (0);
}
