/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 04:35:51 by tprak             #+#    #+#             */
/*   Updated: 2017/06/26 22:18:39 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwordlen(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(str = (char**)malloc(sizeof(*str) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (i < ft_countwords(s, c))
	{
		k = 0;
		if (!(str[i] = ft_strnew(ft_countwordlen(&s[j], c) + 1)))
			str[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}
