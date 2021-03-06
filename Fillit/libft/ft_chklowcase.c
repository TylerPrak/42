/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chklowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 22:19:59 by tprak             #+#    #+#             */
/*   Updated: 2017/06/26 22:21:26 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chklowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] >= 65 && str[i] <= 90)
	{
		if (str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}
