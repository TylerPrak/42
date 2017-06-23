/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 04:35:51 by tprak             #+#    #+#             */
/*   Updated: 2017/06/22 04:51:08 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int		k;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_countwords(s, c);
	if (!s || !(str = (char**)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	while (i < len)
	{
		k = 0;
		if (!(str[i] = ft_strnew(len + 1)))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
		i++;
	}
	return (str);
}
