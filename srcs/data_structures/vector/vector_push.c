/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:08:08 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/16 00:00:11 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

bool vector_push(vector *vect, void *element)
{
	size_t	vect_size;

	if (vect == NULL)
		return (false);
	vect_size = vector_size(vect);
	if (vector_resize(vect, vect_size + 1) == false)
		return (false);
	vector_set(vect, vect_size, element);
	return (true);
}