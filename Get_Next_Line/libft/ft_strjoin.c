/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 23:15:03 by tprak             #+#    #+#             */
/*   Updated: 2017/10/11 04:57:41 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!s1 || !s2 || !(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		str[i] = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != '\0')
	{
		str[i] = *(s2 + j);
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
