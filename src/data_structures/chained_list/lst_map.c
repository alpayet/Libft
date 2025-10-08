/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:57:03 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:53:09 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_list	*lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst_node	*node;
	t_list		*lst_f;
	t_lst_node	*new_node_f;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lst_f = lst_new(f(lst->first->content));
	if (lst_f == NULL)
		return (NULL);
	node = lst->first->next;
	while (node != NULL)
	{
		new_node_f = lst_node_new(f(node->content));
		if (new_node_f == NULL)
		{
			lst_clear(lst_f, del);
			return (NULL);
		}
		lst_add_back(lst_f, new_node_f);
		node = node->next;
	}
	return (lst_f);
}
