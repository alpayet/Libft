/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_extract_priority.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:26:46 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/25 03:20:47 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static void		move_down(heap *heap, size_t parent_index);
static size_t	get_priority_child_index(heap *heap, size_t parent_index);
static void		swap_with_child(heap *heap, size_t parent_index, size_t child_index);

void	*heap_extract_priority(heap *heap)
{
	entry	*root_entry;
	entry	*last_node_entry;

	root_entry = vector_get(heap->vect, 0);
	last_node_entry = vector_get(heap->vect, heap->vect->size - 1);
	vector_set(heap->vect, 0, last_node_entry);
	vector_resize(heap->vect, heap->vect->size - 1);
	move_down(heap, 0);
	return (root_entry->value);
}

static void	move_down(heap *heap, size_t parent_index)
{
	size_t	priority_child_index;
	entry	*priority_child_entry;
	entry	*parent_entry;

	while (2 * parent_index + 1 < heap->vect->size)
	{
		priority_child_index = get_priority_child_index(heap, parent_index);
		priority_child_entry = vector_get(heap->vect, priority_child_index);
		parent_entry = vector_get(heap->vect, parent_index);
		if (heap->key_cmp(parent_entry->key, priority_child_entry->key) < 0)
		{
			swap_with_child(heap, parent_index, priority_child_index);
			parent_index = priority_child_index;
		}
		else
			break ;
	}
}

static size_t	get_priority_child_index(heap *heap, size_t parent_index)
{
	size_t	priority_child_index;
	entry	*first_child_entry;
	entry	*second_child_entry;

	priority_child_index = 2 * parent_index + 1;
	first_child_entry = vector_get(heap->vect, priority_child_index);
	if (priority_child_index + 1 < heap->vect->size)
		second_child_entry = vector_get(heap->vect, priority_child_index + 1);
	else
		second_child_entry = NULL;
	if (second_child_entry != NULL &&
		heap->key_cmp(first_child_entry->key, second_child_entry->key) < 0)
		priority_child_index++;
	return (priority_child_index);
}

static void	swap_with_child(heap *heap, size_t parent_index, size_t child_index)
{
	entry	*child_entry;
	entry	*parent_entry_temp;

	parent_entry_temp = vector_get(heap->vect, parent_index);
	child_entry = vector_get(heap->vect, child_index);
	vector_set(heap->vect, parent_index, child_entry);
	vector_set(heap->vect, child_index, parent_entry_temp);
}