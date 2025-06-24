/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:30:49 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/23 02:27:20 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
bool				hashtbl_resize(hashtbl *h);
t_list				*hashtbl_bucket(hashtbl *h, char *key);
t_hashtbl_status	hashtbl_bucket_prepend(vector *vect,
	t_list **bucket, char *key, void *value);
entry				*hashtbl_find_entry(t_list *bucket, char *key);

t_hashtbl_status hashtbl_put(hashtbl *h, char *key, void *value)
{
	t_list	*bucket;
	entry	*entry;

	if (h == NULL || key == NULL || h->vect == NULL)
		return (HASHTBL_ERR_INVALID);
	if (hashtbl_resize(h) == false)
		return (HASHTBL_ERR_ALLOC);
	bucket = hashtbl_bucket(h, key);
	entry = hashtbl_find_entry(bucket, key);
	if (entry == NULL)
	{
		if (hashtbl_bucket_prepend(h->vect, &bucket,
				key, value) == HASHTBL_ERR_ALLOC)
			return (HASHTBL_ERR_ALLOC);
		t_list	*test = hashtbl_bucket(h, key);
		if(!test)
			return(HASHTBL_ERR_INVALID);
		h->count++;
	}
	else
		entry->value = value;
	return (HASHTBL_OK);
}
