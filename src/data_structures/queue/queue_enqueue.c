/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_enqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:15:06 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/16 20:52:25 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static void	queue_set(queue *q, size_t index, void *element)
{
	char	*entry_ptr;

	entry_ptr = (char *)q->data + (index * q->element_size);
	ft_memmove(entry_ptr, element, q->element_size);
}

//initial case: [end of queue][start of queue][free space]
//Goal: move the the logical head of the queue (from front to end of old buffer)
//		to the newly allocated space, making the queue elements logically contiguous in the enlarged buffer.
//final result: [end of queue][free space][start of queue]
static void reorganize_queue(queue *q)
{
	char	*new_front_ptr;
	char	*old_front_ptr;

	new_front_ptr = (char *)q->data + (q->front + q->capacity) * q->element_size;
	old_front_ptr = (char *)q->data + q->front * q->element_size;
	ft_memmove(new_front_ptr, old_front_ptr, (q->capacity - q->front) * q->element_size);
	q->front = q->front + q->capacity;
}

bool queue_enqueue(queue *q, void *element)
{
	size_t	new_capacity;
	void	*new_data;

	if (q == NULL)
		return (false);
	if (q->size + 1 > q->capacity)
	{
		if (q->size + 1 > q->capacity * 2)
			new_capacity = q->size + 1;
		else
			new_capacity = q->capacity * 2;
		new_data = ft_realloc(q->data,
			q->capacity * q->element_size, new_capacity * q->element_size);
		if (new_data == NULL)
			return (false);
		q->data = new_data;
		reorganize_queue(q);
		q->capacity = new_capacity;
	}
	queue_set(q, (q->front + q->size) % q->capacity, element);
	q->size = q->size + 1;
	return (true);
}