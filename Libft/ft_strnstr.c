/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 01:30:02 by tprak             #+#    #+#             */
/*   Updated: 2017/06/25 18:32:03 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t j;
	size_t i;
	size_t tmp;

	j = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (*big != '\0' && j < len)
	{
		tmp = j - 1;
		i = 0;
		while (big[i] == little[i] && ++tmp < len)
			if (little[++i] == '\0')
				return ((char*)big);
		big++;
		j++;
	}
	return (NULL);
}
