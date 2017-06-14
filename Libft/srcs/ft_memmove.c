/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 02:39:50 by tprak             #+#    #+#             */
/*   Updated: 2017/06/14 02:43:55 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	i = 0;
	if (len > ft_strlen(src))
		return (void*)src;
	while (i < len && ft_strlen(src) < ft_strlen(dst))
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
