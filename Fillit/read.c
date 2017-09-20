/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 04:52:00 by tprak             #+#    #+#             */
/*   Updated: 2017/09/15 05:46:52 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_hash_to_letter(char *buf, int i, char c)
{
	while (buf[i] != '\0' && i < BUF_SIZE)
	{
		if (buf[i] == '#')
			buf[i] = c;
		i++;
	}
}

void	ft_init_tranpos(t_tet_piece *tetris)
{
	tetris->tranpos.y = -1;
	tetris->tranpos.x = -1;
}

int		ft_read(t_tet_piece *tetris, t_var *vl, int i)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while (((ret = read(vl->fd, buf, BUF_SIZE)) != 0) && i < 27)
	{
		buf[ret] = '\0';
		if (!(ft_valid_lines(buf) == 1 && ft_valid_tetris(buf) == 1))
			return (-1);
		ft_strcpy(tetris[i].buf, buf);
		ft_hash_to_letter(tetris[i].buf, 0, LETTER(i));
		ft_init_tranpos(&tetris[i]);
		tetris[i].letter = LETTER(i);
		vl->lastret = ret;
		i++;
	}
	if (vl->lastret != 20 || i > 26)
		return (-1);
	return (i);
}
