/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:47:23 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/16 00:34:24 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void *queue_peek(queue *q)
{
	if (q == NULL || q->data == NULL || q->size == 0)
		return (NULL);
	return ((char *)q->data + q->front * q->element_size);
}