/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 04:19:39 by tprak             #+#    #+#             */
/*   Updated: 2017/06/22 04:26:30 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *node;
	t_list *new;

	if (!lst)
		return (NULL);
	node = f(lst);
	new = node;
	while (node->next != NULL)
	{
		lst = lst->next;
		node->next = f(lst);
		if (!node->next)
		{
			free(node->next);
			return (NULL);
		}
		node = node->next;
	}
	return (new);
}
