/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 04:53:38 by tprak             #+#    #+#             */
/*   Updated: 2017/06/09 05:05:37 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*strrchr(const char *s, int c)
{
	int i;

	i = (int)ft_strlen(s) + 1;
	while (i-- > 0)
		if (*(s + i) == (char)c)
			return ((char*)s + i);
	return (NULL);
}
