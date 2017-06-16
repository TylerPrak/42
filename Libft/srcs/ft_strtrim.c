/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 02:28:30 by tprak             #+#    #+#             */
/*   Updated: 2017/06/16 02:31:46 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(s));
	if (!s || !str)
		return (NULL);
	while (!(!*s))
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
