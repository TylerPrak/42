/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hashes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 06:00:21 by tprak             #+#    #+#             */
/*   Updated: 2017/09/15 06:02:48 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_hash_up(char *buf, int i)
{
	if (buf[i - 5] == '#' && (i - 5) >= 0)
		return (1);
	else
		return (0);
}

int		ft_check_hash_right(char *buf, int i)
{
	if (buf[i + 1] == '#' && (i + 1) < BUF_SIZE)
		return (1);
	else
		return (0);
}

int		ft_check_hash_left(char *buf, int i)
{
	if (buf[i - 1] == '#' && (i - 1) >= 0)
		return (1);
	else
		return (0);
}

int		ft_check_hash_down(char *buf, int i)
{
	if (buf[i + 5] == '#' && (i + 5) < BUF_SIZE)
		return (1);
	else
		return (0);
}
