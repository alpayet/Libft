/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:43:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 01:05:49 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_node *node_at(t_list *lst, size_t index)
{
	t_node	*node;

	if (lst == NULL || index >= lst->size)
		return (NULL);
	node = lst->first;
	while (index != 0 && node != NULL)
	{
		index--;
		node = node->next;
	}
	return (node);
}
