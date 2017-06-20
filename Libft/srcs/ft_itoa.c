/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:20:59 by tprak             #+#    #+#             */
/*   Updated: 2017/06/20 01:47:07 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_getlen(int n, size_t len)
{
	int i;

	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (0 < num)
	{
		num /= 10;
		i++;
	}
	*len = i;
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	ft_getlen(n, &len);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n > 9)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	str[--len] = n + '0';
	return (str);
}
