/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:46:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/23 02:57:46 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void vector_delete(vector *vect, void (*del)(void *))
{
	size_t	i;
	void	*elem_ptr;

	if (vect == NULL)
		return ;
	if (del != NULL)
	{
		i = 0;
		while (i < vect->size)
		{
			elem_ptr = vector_get(vect, i);
			if (elem_ptr != NULL)
				del(elem_ptr);
			i++;
		}
	}
	free(vect->data);
	free(vect);
}
