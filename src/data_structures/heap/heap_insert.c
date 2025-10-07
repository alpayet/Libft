/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:30:29 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/25 02:07:46 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static void	move_up(heap *heap, size_t child_index);

bool	heap_insert(heap *heap, void *key, void *value)
{
	if (heap == NULL || heap->vect == NULL)
		return (false);
	vector_push(heap->vect, &(entry){key, value});
	move_up(heap, heap->vect->size - 1);
	return (true);
}

static void	move_up(heap *heap, size_t child_index)
{
	entry	*child_entry;
	size_t	parent_index;
	entry	*parent_entry;
	entry	*parent_entry_temp;

	while (child_index > 0)
	{
		parent_index = (child_index - 1) / 2;
		child_entry = vector_get(heap->vect, child_index);
		parent_entry = vector_get(heap->vect, parent_index);
		if (heap->key_cmp(child_entry->key, parent_entry->key) > 0)
		{
			parent_entry_temp = parent_entry;
			vector_set(heap->vect, parent_index, child_entry);
			vector_set(heap->vect, child_index, parent_entry_temp);
			child_index = parent_index;
		}
		else
			break ;
	}
}