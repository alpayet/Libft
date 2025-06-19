/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:46:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/19 02:29:19 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void vector_delete(vector *vect, void (*del)(void *))
{
	size_t	i;

	if (vect == NULL)
		return ;
	if (del != NULL)
	{
		i = 0;
		while (i < vect->size)
		{
			del(vector_get(vect, i));
			i++;
		}
	}
	free(vect->data);
	free(vect);
}
