/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_bucket_prepend.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 04:18:37 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 02:30:42 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_list					*hashtbl_bucket(t_hashtbl *h, void *key);
void					hashtbl_change_bucket(t_vector *vect,
							t_list **new_bucket_ptr, void *key);

static t_entry	*new_entry(void *key, void *value)
{
	t_entry	*new_entry;

	new_entry = malloc(sizeof(t_entry));
	if (new_entry == NULL)
		return (NULL);
	new_entry->key = key;
	new_entry->value = value;
	return (new_entry);
}

static t_hashtbl_status	init_bucket(t_vector *vect,
	t_list **bucket, t_entry *entry)
{
	*bucket = lst_new(entry);
	if (*bucket == NULL)
	{
		free(entry);
		return (HASHTBL_ERR_ALLOC);
	}
	hashtbl_change_bucket(vect, bucket, entry->key);
	return (HASHTBL_OK);
}

t_hashtbl_status	hashtbl_bucket_prepend(t_vector *vect, t_list *bucket,
		void *key, void *value)
{
	t_entry		*entry;
	t_lst_node	*new_node;

	if (vect == NULL || key == NULL)
		return (HASHTBL_ERR_INVALID);
	entry = new_entry(key, value);
	if (entry == NULL)
		return (HASHTBL_ERR_ALLOC);
	if (bucket == NULL)
	{
		if (init_bucket(vect, &bucket, entry) == HASHTBL_ERR_ALLOC)
			return (HASHTBL_ERR_ALLOC);
	}
	else
	{
		new_node = lst_node_new(entry);
		if (new_node == NULL)
		{
			free(entry);
			return (HASHTBL_ERR_ALLOC);
		}
		lst_add_front(bucket, new_node);
	}
	return (HASHTBL_OK);
}
