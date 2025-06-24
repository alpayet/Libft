/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 00:43:48 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 00:44:01 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_node	*node_new(void *content)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}