/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 23:00:50 by tprak             #+#    #+#             */
/*   Updated: 2017/10/11 04:53:46 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str || !s)
		return (NULL);
	while (i < (len))
	{
		*(str + i) = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
