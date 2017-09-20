/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:53:55 by tprak             #+#    #+#             */
/*   Updated: 2017/06/26 21:05:19 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < (n - 1))
		i++;
	return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
