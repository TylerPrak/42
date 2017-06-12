/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 23:03:21 by tprak             #+#    #+#             */
/*   Updated: 2017/06/11 23:05:41 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;
	size_t i;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	i = 0;

	while (i++ < n)
	{
		if (*s2 == (unsigned char)c)
			return (dst + i + 1);
		*s1++ = *s2++;
	}
	return (NULL);
}
