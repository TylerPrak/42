/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:04:20 by tprak             #+#    #+#             */
/*   Updated: 2017/06/11 22:06:42 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	size_t i;

	i = -1;
	str = (unsigned char*)s;
	while (++i < n)
	{
		if (*str++ == (unsigned char)c)
			return (str - 1);
	}
	return (NULL);
}
