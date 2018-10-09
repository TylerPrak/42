/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 23:57:13 by tprak             #+#    #+#             */
/*   Updated: 2017/06/25 18:04:35 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (*big != '\0')
	{
		i = 0;
		while (big[i] == little[i])
			if (little[++i] == '\0')
				return ((char*)big);
		big++;
	}
	return (NULL);
}
