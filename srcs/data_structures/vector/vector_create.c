/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:29:55 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/10 20:47:49 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

vector *vector_create(size_t capacity, size_t element_size)
{
	vector	*vect;

	vect = malloc(sizeof(vector));
	if (vect == NULL)
		return (NULL);
	vect->capacity = capacity;
	vect->element_size = element_size;
	vect->data = malloc(capacity * element_size);
	if (vect->data == NULL)
		return (NULL);
	vect->size = 0;
	return (vect);
}
