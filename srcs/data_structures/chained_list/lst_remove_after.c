/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:53:41 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 02:10:11 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_remove_after(t_list *lst, t_node *node, void (*del)(void*))
{
	t_node *node_del;

	if (lst == NULL || node == NULL)
		return ;
	node_del = node->next;
	if (node_del == NULL)
		return ;
	if (node_del == lst->last)
		lst->last = node;
	node->next = node_del->next;
	lst_delone(node_del, del);
	if (lst->size != 0)
		lst->size--;
}
