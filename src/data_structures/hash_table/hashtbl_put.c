/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:30:49 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:52:48 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

bool				hashtbl_resize(t_hashtbl *h);
t_list				*hashtbl_bucket(t_hashtbl *h, void *key);
t_hashtbl_status	hashtbl_bucket_prepend(t_vector *vect, t_list *bucket,
						void *key, void *value);
t_entry				*hashtbl_find_entry(t_list *bucket, void *key,
						int (*key_cmp)(void *first_key, void *second_key));

t_hashtbl_status	hashtbl_put(t_hashtbl *h, void *key, void *value)
{
	t_list	*bucket;
	t_entry	*entry;

	if (h == NULL || key == NULL || h->vect == NULL)
		return (HASHTBL_ERR_INVALID);
	if (hashtbl_resize(h) == false)
		return (HASHTBL_ERR_ALLOC);
	bucket = hashtbl_bucket(h, key);
	entry = hashtbl_find_entry(bucket, key, h->key_cmp);
	if (entry == NULL)
	{
		if (hashtbl_bucket_prepend(h->vect, bucket, key,
				value) == HASHTBL_ERR_ALLOC)
			return (HASHTBL_ERR_ALLOC);
		h->count++;
	}
	else
		entry->value = value;
	return (HASHTBL_OK);
}
