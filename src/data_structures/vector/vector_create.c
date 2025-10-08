/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:29:55 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:52:29 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_vector	*vector_create(size_t capacity, size_t element_size)
{
	t_vector	*vect;

	vect = malloc(sizeof(t_vector));
	if (vect == NULL)
		return (NULL);
	vect->capacity = capacity;
	vect->element_size = element_size;
	vect->data = ft_calloc(capacity, element_size);
	if (vect->data == NULL)
	{
		free(vect);
		return (NULL);
	}
	vect->size = 0;
	return (vect);
}
