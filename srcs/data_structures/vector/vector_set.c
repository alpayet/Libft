/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:46:56 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/10 20:48:00 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void vector_set(vector *vect, size_t index, void *element)
{
	char	*entry_ptr;

	if (index >= vect->size)
		return ;
	entry_ptr = (char *)vect->data + (index * vect->element_size);
	ft_memmove(entry_ptr, element, vect->element_size);
}
