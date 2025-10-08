/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:43:59 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 02:01:08 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_queue	*queue_create(size_t capacity, size_t element_size)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (q == NULL)
		return (NULL);
	q->capacity = capacity;
	q->element_size = element_size;
	q->data = ft_calloc(capacity, element_size);
	if (q->data == NULL)
	{
		free(q);
		return (NULL);
	}
	q->size = 0;
	q->front = 0;
	return (q);
}
