/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:09:36 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/24 23:28:47 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

heap	*heap_create(size_t capacity, int (*key_cmp)(void *first_key, void *second_key))
{
	heap	*heap;

	heap = malloc(sizeof(*heap));
	if (heap == NULL)
		return (NULL);
	heap->vect = vector_create(capacity, sizeof(entry));
	if (heap->vect == NULL)
	{
		free(heap);
		return (NULL);
	}
	heap->key_cmp = key_cmp;
	return (heap);
}