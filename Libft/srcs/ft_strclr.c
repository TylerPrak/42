/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 22:36:02 by tprak             #+#    #+#             */
/*   Updated: 2017/06/14 22:37:06 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strclr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		*s = '\0';
		i++;
	}
}