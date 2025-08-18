/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 01:53:28 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/15 16:37:35 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void lst_remove_first(t_list *lst, void (*del)(void*))
{
	t_lst_node	*node_del;
	if (lst == NULL || lst->first == NULL)
		return ;
	node_del = lst->first;
	lst->first = node_del->next;
	if (lst->last == node_del)
		lst->last = NULL;
	lst_delone(node_del, del);
	if (lst->size != 0)
		lst->size--;
}