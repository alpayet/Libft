/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_dequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:27:32 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/16 00:38:27 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void *queue_dequeue(queue *q)
{
	size_t old_front;

	if (q == NULL || q->capacity == 0 || q->size == 0 || q->data == NULL)
		return (NULL);
	old_front = q->front;
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return ((char *)q->data + old_front * q->element_size);
}