/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:46:53 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/15 23:59:42 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

bool vector_resize(vector *vect, size_t new_size)
{
	size_t	new_capacity;
	void	*new_data;

	if (vect == NULL)
		return (false);
	if (new_size > vect->capacity)
	{
		if (new_size > vect->capacity * 2)
			new_capacity = new_size;
		else
			new_capacity = vect->capacity * 2;
		new_data = ft_realloc(vect->data,
			vect->capacity * vect->element_size, new_capacity * vect->element_size);
		if (new_data == NULL)
			return (false);
		vect->capacity = new_capacity;
		vect->data = new_data;
	}
	vect->size = new_size;
	return (true);
}
