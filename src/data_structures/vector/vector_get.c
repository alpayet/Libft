/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:46:48 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/16 00:22:36 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void *vector_get(vector *vect, size_t index)
{
	if (vect == NULL || vect->data == NULL || index >= vect->size)
		return (NULL);
	return ((char *)vect->data + (index * vect->element_size));
}
