/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:40:43 by tprak             #+#    #+#             */
/*   Updated: 2017/06/26 20:56:49 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && n > 0 && ((*s1 == *s2) || \
		(*s1 + 32) == *s2 || (*s1 - 32) == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if ((*s1 == '\0' && *s2 == '\0') || n == 0)
		return (1);
	return (0);
}
