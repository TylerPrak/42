/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 14:43:39 by tprak             #+#    #+#             */
/*   Updated: 2017/09/15 05:38:44 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_connections(char *buf, int i)
{
	int count;

	count = 0;
	if (ft_check_hash_up(buf, i) == 1)
		count++;
	if (ft_check_hash_right(buf, i) == 1)
		count++;
	if (ft_check_hash_left(buf, i) == 1)
		count++;
	if (ft_check_hash_down(buf, i) == 1)
		count++;
	return (count);
}

int		ft_valid_lines(char *buf)
{
	int i;
	int hashcount;

	hashcount = 0;
	i = 0;
	while (buf[i] != '\0' || buf[i] == '.' || buf[i] == '#' || buf[i] == '\n')
	{
		if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' ||
			buf[19] != '\n' || (buf[20] != '\n' && buf[20] != '\0'))
			return (0);
		if (buf[i] == '#')
			hashcount++;
		i++;
	}
	if (hashcount == 4)
		return (1);
	else
		return (0);
}

int		ft_valid_tetris(char *buf)
{
	int connects;
	int i;
	int hashes;

	i = 0;
	connects = 0;
	hashes = 0;
	while (buf[i] != '\0' && i <= BUF_SIZE)
	{
		if (buf[i] == '#')
		{
			connects += ft_count_connections(buf, i);
			hashes++;
		}
		i++;
	}
	if ((connects == 6 || connects == 8) && hashes == 4)
		return (1);
	else
		return (0);
}

int		ft_check_letter(t_var *vl, int ysum, int xsum)
{
	if (xsum >= vl->size || ysum >= vl->size)
		return (0);
	if (vl->map[ysum][xsum] == '.')
		return (1);
	return (0);
}
