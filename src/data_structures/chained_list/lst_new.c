/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:26:30 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/15 16:37:57 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_list	*lst_new(void *content)
{
	t_list	*list;
	t_lst_node	*node;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	node = lst_node_new(content);
	if (node == NULL)
	{
		free (list);
		return (NULL);
	}
	list->first = node;
	list->last = node;
	list->size = 1;
	return (list);
}
