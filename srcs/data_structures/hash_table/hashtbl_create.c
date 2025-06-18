/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:24:16 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/17 23:24:21 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

hashtbl *hashtbl_create(size_t capacity)
{
	hashtbl	*h;

	h = malloc(sizeof(hashtbl));
	if (h == NULL)
		return (NULL);
	h->vect = vector_create(capacity, sizeof(void *));
	if (h->vect == NULL)
	{
		free(h);
		return (NULL);
	}
	return (h);
}