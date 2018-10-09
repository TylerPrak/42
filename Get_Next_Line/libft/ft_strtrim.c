/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 02:28:30 by tprak             #+#    #+#             */
/*   Updated: 2017/06/26 20:24:28 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strlentrim(char *s, int *len, int *wordstart)
{
	int i;
	int j;
	int x;
	int size;

	i = 0;
	j = 0;
	x = 0;
	size = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] != '\0')
		j++;
	size = j;
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
	{
		j--;
		x++;
	}
	size = size - i - x;
	if (size > 0)
		*len = size;
	else
		*len = 1;
	*wordstart = x;
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		wordstart;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ft_strlentrim((char*)s, &len, &wordstart);
	i = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i + wordstart] != '\0')
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
