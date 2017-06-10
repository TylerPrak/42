/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 01:30:02 by tprak             #+#    #+#             */
/*   Updated: 2017/06/10 01:34:29 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t j;
	size_t i;

	i = 0;
	j = 0;
	if ((int)ft_strlen(little) == 0)
	{
		return ((char*)big);
	}
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char*)big + i - j + 1);
	}
	return (NULL);
}
