/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 02:57:35 by tprak             #+#    #+#             */
/*   Updated: 2017/06/23 07:27:52 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	if (size > (i + 1))
	{
		while (k < (size - i - 1))
		{
			dst[i + k] = src[k];
			k++;
		}
		dst[i + k] = '\0';
	}
	if (i <= size)
		return (i + j);
	else
		return (size + j);
}
