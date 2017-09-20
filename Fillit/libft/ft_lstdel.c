/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:48:22 by tprak             #+#    #+#             */
/*   Updated: 2017/06/23 07:39:18 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	if (!alst || !del)
		return ;
	node = *alst;
	while (node != NULL)
	{
		del(node->content, node->content_size);
		free(node);
		node = node->next;
	}
	*alst = NULL;
}
