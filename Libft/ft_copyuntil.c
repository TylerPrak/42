/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 05:01:13 by tprak             #+#    #+#             */
/*   Updated: 2017/10/11 04:56:57 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_copyuntil(char **dst, char *src, char c)
{
	int	i;
	int	count;
	int	pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (*dst == NULL)
		*dst = ft_strnew(i);
	i = 0;
	while (i < pos)
	{
		*(*dst + i) = src[i];
		i++;
	}
	*(*dst + i) = '\0';
	return (pos);
}
