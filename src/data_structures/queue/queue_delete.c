/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:50:13 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/19 03:31:23 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void queue_delete(queue *q, void (*del)(void *))
{
	size_t	i;
	size_t	index_in_queue;

	if (q == NULL)
		return ;
	if (del != NULL && q->data != NULL && q->capacity != 0)
	{
		i = 0;
		while (i < q->size)
		{
			index_in_queue = (q->front + i) % q->capacity;
			del((char *)q->data + (index_in_queue * q->element_size));
			i++;
		}
	}
	free(q->data);
	free(q);
}