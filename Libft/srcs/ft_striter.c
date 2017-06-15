/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:23:45 by tprak             #+#    #+#             */
/*   Updated: 2017/06/15 14:24:33 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void(*f)(char *))
{
	size_t i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(s);
		i++;
	}
}
