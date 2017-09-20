/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprak <tprak@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 04:19:39 by tprak             #+#    #+#             */
/*   Updated: 2017/06/24 04:17:41 by tprak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *node;
	t_list *newlist;
	t_list *tmp;

	newlist = (t_list*)malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	tmp = NULL;
	while (lst != NULL)
	{
		node = (t_list*)malloc(sizeof(t_list));
		if (node == NULL)
			return (NULL);
		node = f(lst);
		if (tmp != NULL)
			tmp->next = node;
		else
			newlist = node;
		tmp = node;
		lst = lst->next;
	}
	return (newlist);
}
