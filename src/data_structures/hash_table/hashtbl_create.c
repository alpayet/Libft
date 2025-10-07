/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:24:16 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/24 22:28:58 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

hashtbl	*hashtbl_create(size_t capacity, int (*key_cmp)(void *first_key, void *second_key))
{
	hashtbl	*h;

	h = malloc(sizeof(hashtbl));
	if (h == NULL)
		return (NULL);
	if (capacity == 0)
		capacity = INITIAL_BUCKET_COUNT;
	h->vect = vector_create(capacity, sizeof(t_list *));
	h->key_cmp = key_cmp;
	if (h->vect == NULL)
	{
		free(h);
		return (NULL);
	}
	h->vect->size = capacity;
	h->count = 0;
	return (h);
}
