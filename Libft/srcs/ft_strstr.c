/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 23:57:13 by tprak             #+#    #+#             */
/*   Updated: 2017/06/10 00:02:42 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if ((int)ft_strlen(little) == 0)
	{
		return ((char*)big);
	}
	while (++i < (int)ft_strlen(big) + 1)
	{
		if (big[i] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char*)big + i - j + 1);
		}
	}
	return (NULL);
}
